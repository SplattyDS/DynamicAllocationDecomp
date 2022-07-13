#ifndef SM64DS_NDSCORE_INCLUDED
#define SM64DS_NDSCORE_INCLUDED

#include "SM64DS_Common.h"

namespace CP15
{
	void EnableDTCM();													//Enables the DTCM
	u32 GetDTCMBaseAddress();										//Returns the DTCM base address
	void EnableMPU();													//Enables the MPU
	void DisableMPU();													//Disables the MPU
	void MPUDataRegion1(u32 settings);								//Sets data/unified region 1 MPU settings
	void MPUDataRegion7(u32 settings);								//Sets data/unified region 7 MPU settings
	u32 MPUGetDataRegion7();										//Returns the MPU's region 7 settings
	void FlushDataCache();												//Flushes the data cache
	void FlushAndInvalidateDataCache();									//Flushes and invalidates the data cache
	void FlushDataCache(u32 startVA, u32 size);				//Flushes the data cache (virtual address)
	void InvalidateDataCache(u32 startVA, u32 size);			//Invalidates the data cache (virtual address)
	void InvalidateInstructionCache(u32 startVA, u32 size);	//Invalidates the instruction cache (virtual address)
	void FlushAndInvalidateDataCache(u32 startVA, u32 size);	//Flushes and invalidates the data cache (virtual address)
	void DrainWriteBuffer();											//Finish all bus transactions and end writes
	void WaitForInterrupt();											//Wait for interrupt
	void SystemSetup();													//Called right after _start, sets up cache, MPU and memory
}


namespace IRQ
{
	typedef void(*IRQHandler)();

	struct DmaTimData
	{
		IRQHandler function;					//The extended function to call
		u32 unk04;							//one shot if 0?
		u32 unk08;
	};

	extern IRQHandler IRQFunctions[22];			//Contains all IRQ handlers and are indexed by IRQ number
	extern u16 DmaTimIndices[8];			//Contains the corresponding IRQ bit shift values of DMA and TIM peripherals
	extern DmaTimData DmaTimFunctions[8];		//Contains special DMA/TIM IRQ handlers (4 each) which are preferred over the corresponding irqFunction
	extern u32 IRQCheckBits;				//Contains the check bits used by BIOS, set by user handler to mark one IRQ as finished
	extern IRQHandler UserIRQAddress;			//Function pointer to UserInterruptHandler, set by _start 

	u32 Disable();							//Disables interrupts and returns the previous state
	u32 Enable();							//Enables interrupts and returns the previous state
	u32 Restore(u32 prevCPSR);		//Restores interrupts to the state given by prevCPSR and returns the previous state
	u32 DisableAll();						//Disables IRQs and FIQs
	u32 RestoreAll(u32 prevCPSR);		//Restores IRQ and FIQ bits to the state given by prevCPSR
	bool SetIRQState(bool enable);				//Sets the IRQ state and returns wheter interrupts have been enabled before
	bool SetFIQState(bool enable);				//Sets the FIQ state and returns wheter fast interrupts have been enabled before
	u32 ClearInterrupts(u32 mask);	//Acknowledges masked IRQ flags and returns the previous IRQ flags
	u32 DisableIRQs(u32 mask);		//Disables interrupts according to mask and returns the previous IE state
	u32 EnableIRQs(u32 mask);			//Enables interrupts according to mask and returns the previous IE state
	u32 SetIRQs(u32 mask);			//Assigns mask to IE and returns the previous IE state
	IRQHandler GetIRQHandler(u32 irq);		//Returns the IRQHandler assigned to the given IRQ number
	void SetIRQHandler(u32 mask, IRQHandler function);	//Installs the corresponding IRQ handler to the IRQs given by mask

	void VBlankHandler();						//Called on v-blank
	void EmptyHandler();						//Called when no IRQ handler is installed
	void Tim0OverflowHandler();					//Called on TIM0 overflow
	void Tim1OverflowHandler();					//Called on TIM1 overflow
	void Tim2OverflowHandler();					//Called on TIM2 overflow
	void Tim3OverflowHandler();					//Called on TIM3 overflow
	void Dma0Handler();							//Called on DMA0 interrupt
	void Dma1Handler();							//Called on DMA1 interrupt
	void Dma2Handler();							//Called on DMA2 interrupt
	void Dma3Handler();							//Called on DMA3 interrupt
	void IPCRxFifoNotEmptyHandler();			//Called when IPC RX FIFO is not empty
	void GameCardIREQMCHandler();				//Called when an interrupt is asserted on IREQ_MC
	void DmaTimHandler();						//Called by DMA/TIM(0-3) handlers
	void UserInterruptHandler();				//Interrupt handler called by BIOS after an interrupt event, address at 0x023C3FFC (setup by _start)

}


struct ARMMathState //Struct storing math processor state related data
{
	u64 divNumerator;
	u64 divDenominator;
	u64 sqrtParam;
	u16 divMode;
	u16 sqrtMode;
};

struct ARMContext
{
	u32 cpsr;
	u32 r0;
	u32 r1;
	u32 r2;
	u32 r3;
	u32 r4;
	u32 r5;
	u32 r6;
	u32 r7;
	u32 r8;
	u32 r9;
	u32 r10;
	u32 r11;
	u32 r12;
	u32 r13;
	u32 r14;
	u32 targetPC;
	u32 swiSP;
	ARMMathState savedMath;
};

namespace cstd
{
	void fdiv_async(Fix12i numerator, Fix12i denominator);
	Fix12i fdiv_result();  //Returns the division result
	s64 ldiv_result(); //Returns the 64 bit division result (which type?)
	void reciprocal_async(Fix12i x); //Computes 1/x

	[[noreturn]] void _start(); //ROM entry point, resets the NDS on return = 0x02004800
	void __builtin_trap(); //Abort functionality. Triggers an undefined instruction (UDF)
	void __assert(const char* file, const char* line, const char* exp, s32 eval); //Assertion that causes hangup if eval != 0
}

extern "C"
{
	u32 ARMProcessorMode(); //Returns the current ARM mode bits
	bool ARMSaveContext(ARMContext* context); //Saves the current context, returns 0 if successful
	void ARMRestoreContext(ARMContext* context); //Restores the context

	enum IPCStatus
	{
		success = 0,
		error = -1,
		fifoFull = -2
	};

	IPCStatus IPCSend(u32 arg0, u32 arg1, u32 arg2); //Transmits data to the ARM7

	void OSReadROMArea(u32 src, u32 dest, u32 size); //Reads size bytes from the gamecard at src and writes to dest = 0x01FFDBD8
	//ROMCTRL_SETTINGS = 0x027FFE60

	void ARMMathSaveState(ARMMathState* location); //Saves the ARM math state
	void ARMMathLoadState(ARMMathState* location); //Loads the ARM math state

	void DMAStartTransferFB(char channel, u32 src, u32 dest, u32 ctrl); //Starts DMA Transfer and waits two load cycles
	void DMAStartTransfer(char channel, u32 src, u32 dest, u32 ctrl);   //Starts DMA Transfer

	void DMASyncWordTransfer(char channel, u32 src, u32 dest, u32 len);  //Synchronous 32-bit DMA transfer (waits until completion)
	void DMASyncHalfTransfer(char channel, u32 src, u32 dest, u32 len);  //Synchronous 16-bit DMA transfer (waits until completion)
	void DMASyncFillTransfer(char channel, u32 dest, u32 fill, u32 len); //Synchronous DMA fill transfer (fills dest with fill len bytes)
}

#endif