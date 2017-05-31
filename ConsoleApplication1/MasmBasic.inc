.nolist
__NO_NOISE__=1	; no "ASCII build" echo please
useXmSave=1
jjtest=0
@64=0
ttStart=0
ttEnd=0
jbit$ equ <"32">
jinvoke equ <invoke>
SIZE_P equ <DWORD>	; int, long, and pointer are 32-bit
rax equ eax
rcx equ ecx
rdx equ edx
rsi equ esi
rdi equ edi
rbx equ ebx
rbp equ ebp
rsp equ esp
@LibUsed$ MACRO quot:=<1>
  if quot
	EXITM <"MasmBasic">
  else
	EXITM <MasmBasic>
  endif
ENDM
IFNDEF _wininc_
	Alloc macro arg
	ENDM
	Free macro arg
	ENDM
	include	\masm32\include\masm32rt.inc
	.686	; JWasm needs this
	.xmm
ENDIF
IFNDEF MbLib$
	MbLib$ equ <includelib \masm32\MasmBasic\MasmBasic.lib>
endif
 MbLib$
Open_for_input	PROTO:DWORD,:DWORD,:DWORD
Open_for_output	PROTO:DWORD,:DWORD,:DWORD
MbResString	PROTO
MbInputP	PROTO
FileReadP	PROTO :DWORD
MbPrint	PROTO
MbStrLen	PROTO
MbStrLenW 	PROTO
MbCopy	PROTO :DWORD, :DWORD, :DWORD
ImgPaintP	PROTO :DWORD, :DWORD, :DWORD
ClearLocalsP	PROTO
MbExistP	PROTO
MbGetFileLen	PROTO :DWORD
; RealComp	PROTO :DWORD,:DWORD,:DWORD
InstrCi	PROTO :DWORD,:DWORD,:DWORD,:DWORD
FindInFile	PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MbReplPrep	PROTO:DWORD,:DWORD,:DWORD,:DWORD
StringFill	PROTO
Float2Asc	PROTO: DWORD, :DWORD, :DWORD
MbVal	PROTO: DWORD, :DWORD, :DWORD
MbFloatCmp	PROTO
MbLoadRich	PROTO
MulCatCopy	PROTO
MbBufferGet	PROTO
MbBufferFix	PROTO
MbBufferInit	PROTO
MbGetSlotPointer	PROTO
; MbZeroString 	PROTO
MbArrayDim	PROTO:DWORD,:DWORD
MbDimStruct	PROTO:DWORD,:DWORD,:DWORD
MbSAP	PROTO
MbStructCopy	PROTO
MbStringErase	PROTO
MbArrayErase	PROTO
MbStructErase	PROTO :DWORD
MbInsert	PROTO
MbArraySwap	PROTO
MbArrayGet 	PROTO :DWORD,:DWORD
MbArrSort	PROTO  :DWORD, :DWORD, :DWORD, :DWORD
MbQSortP	PROTO :DWORD, :DWORD
MbArrayLet 	PROTO
MbDBM	PROTO: DWORD, :DWORD
MbArrayPlot	PROTO :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
MbDbGetRgn	PROTO: DWORD, :DWORD, :DWORD
GetStringID 	PROTO
GetNumID 	PROTO	; get free ID for numerical array
ExternDef	MbProHeap:DWORD
MbAllocP 	PROTO
MbFreeP 	PROTO
RecallP 	PROTO :DWORD,:DWORD,:DWORD,:DWORD
StoreP 	PROTO :DWORD,:DWORD,:DWORD
MbWinStrP	PROTO :DWORD,:DWORD
MbClipP 	PROTO
MbSCP 	PROTO
NewStrP	PROTO
MbwRec	PROTO
ExternDef	MbNewP:NEAR
Externdef	MbError1:NEAR, MbError4:NEAR, MbError5:NEAR, MbError6:NEAR
MbClose	PROTO
MbOpenFile	PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
MbGetCL	PROTO
MbUpperLowerP	PROTO :DWORD, :DWORD
wDataP	PROTO
MbBinP	PROTO
MbTrim	PROTO :DWORD, :DWORD
MbPipe STRUCT
 mphWrite	dd ?
 mphRead	dd ?
 mphProcess	dd ?
 mphEdit	dd ?
 mphProgress	dd ?
 mphNoActivity	dd ?
 mphPosEdit	dd ?
 mphID	dd ?
MbPipe ENDS
EXTERNDEF	lsp:MbPipe
MbTOOLINFO STRUCT
 cbSize    	UINT ?
 uFlags    	UINT ?
 hwnd      	dd ?
 uId       	dd ?
 rect      	RECT <>
 hinst     	dd ?
 lpszText  	dd ?
 lParam    	dd ?
 ; lpReserved	LPVOID ? no good: no tooltips with XP, and doesn't solve the W7 problems
MbTOOLINFO ENDS
ExternDef	MbTIS:MbTOOLINFO
ExternDef	MbErrLine:DWORD
ExternDef	MbFlags:DWORD
ExternDef	gcHeapA:DWORD
ExternDef	gcHeapF:DWORD
ExternDef	MbArrEmpty:DWORD
ExternDef	MbArrTable:DWORD
ExternDef	MbLenTable:DWORD
ExternDef	MbHeapTable:DWORD
ExternDef	MbArGetCTH:NEAR
ExternDef	Tb$:DWORD
ExternDef	Cr$:DWORD
ExternDef	Lf$:DWORD
ExternDef	CrLf$:DWORD
ExternDef	FifHandle:DWORD
ExternDef	hSetWin:DWORD
ExternDef	MbGetFileCount:DWORD
ExternDef	MbCF:DWORD
ExternDef	ccnOld:DWORD
ExternDef	MbCat$:DWORD
ExternDef	MbClips:DWORD
ExternDef	wfd:WIN32_FIND_DATAW
ExternDef	MbOfn:OPENFILENAME
ExternDef	MousePos:POINT
ExternDef	Dw2BinBuffer:DWORD
ExternDef	Dw2BinTable:DWORD
ExternDef	MbHexBuffer:DWORD
ExternDef	FifRetBuf:DWORD
ExternDef	MbExeFolder$:DWORD
ExternDef	EspGlob:DWORD
ExternDef	MbFH:DWORD
ExternDef	DllTable:DWORD
ExternDef	MiscStrings:DWORD
ExternDef	snsFlag:DWORD
ExternDef	snsBuf:DWORD
ExternDef	CrLf_txt:BYTE
ExternDef	wCrLf_txt:WORD
ExternDef	wLf_txt:WORD
ExternDef	txBOM:BYTE
ExternDef	Tab_txt:BYTE
ExternDef	wTab_txt:WORD
ExternDef	txSpTbSpSp:BYTE
ExternDef	Spc1_txt:BYTE
ExternDef	Spc2_txt:BYTE
ExternDef	Spc3_txt:BYTE
ExternDef	Spc4_txt:BYTE
ExternDef	MbDebugTitle:BYTE
ExternDef	txQuest:BYTE
ExternDef	MbDefNum:DWORD
ExternDef	f2sOlly:DWORD
ExternDef	PI:REAL10
ExternDef	MbPiBy180:REAL10
MbSinP	PROTO
ExternDef	MbBytes2Write:DWORD
ExternDef	MbCurSlot:DWORD
ExternDef	MbSlots:DWORD
ExternDef	MbBufferStart:DWORD
ExternDef	gvStart:DWORD
ExternDef	MbError$:DWORD
ExternDef	MbDebugNull:DWORD
ExternDef	MbDebugBuffer:BYTE
ExternDef	MbDebugPtr:DWORD
ExternDef	MbDebugLine:DWORD
ExternDef	MbDebugStop:DWORD
ExternDef	MbDebugR8:REAL8
ExternDef	MbDebugR10:REAL10
ExternDef	MbTmpQw:QWORD
ExternDef	DebFile$:DWORD
ExternDef	MbDebugNotPointer:BYTE
ExternDef	txEmpty:BYTE
ExternDef	StringFillBuffer:BYTE
ExternDef	RichEditUsed:DWORD
Credits MACRO
  ifndef MbCredits
	.DATA
	MbCredits	db "Thanks to all those who have contributed to this library, "
	db "and apologies in case I forgot somebody:", 13, 10, 10
	db "Agner Fog  Alex (Antariy)  BeeOnRope  Bill Cravener  BlackVortex  BogdanOntanu  Damos", 13, 10
	db "daydreamer  dedndave  donkey  DoomyD  drizz  dsouza123  Farabi  fearless  FORTRANS", 13, 10
	db "Greg  herge  Ian_B  japheth  jdoe  Jimg  KeepingRealBusy  lingo  Mark Jones", 13, 10
	db "MichaelW  mineiro  mitchi  Neil  NightWare  Pelle Orinius  PBrennick  qWord  rags", 13, 10
	db "Rainstorm  ramguru  raymond  redskull  Rockoon  shankle  sinsi  Tedd  tetsu-jp", 13, 10
	db "ToutEnMasm  UtillMasm  Vortex  2-Bit Chip", 0
	.CODE
  endif
  MsgBox 0, offset MbCredits, "Credits to Hutch and the Masm32 crew:", MB_OK
ENDM
ifndef usedeb
	usedeb=1		; 0=disable calls to deb and other macros
endif
str$ MACRO DDvalue
LOCAL rvstring
  .DATA
  rvstring db 20 dup (0)
  align 4
  .CODE
  invoke dwtoa, DDvalue, ADDR rvstring
  EXITM <offset rvstring>
ENDM
aChr$ MACRO any_text:VARARG
LOCAL txtname
  .DATA
  txtname db any_text,0
  align 4
  .CODE
  EXITM <OFFSET txtname>
ENDM
aPrint MACRO arg1:REQ,varname:VARARG
  invoke StdOut, repargA(arg1)
  IFNB <varname>
	invoke StdOut, aChr$(varname)
  ENDIF
ENDM
IsUtf8Build MACRO	; Ctrl F6 in RichMasm
  ifnb @Environ(oUtf8)
	EXITM @Environ(oUtf8)
  else
	EXITM <0>
  endif
ENDM
AsmUsed$ MACRO quot:=<1>	; Print "Assembled with ", au$()
LOCAL tmp$
  if quot
	tmp$ CATSTR <">, @Environ(oAssembler), <">
	EXITM tmp$

  else
	EXITM @Environ(oAssembler)
  endif
ENDM
if @InStr(1, AsmUsed$(), <asmc>)
	ifdifi @Environ(oBody), <MasmBasic>
		echo ### Use AsmC at your own risk, see http://masm32.com/board/index.php?topic=902.msg49250#msg49250 ###
	endif
	; OPTION CSTACK:0
endif
TestMasmVersion macro
  ifidn @Version, <614>
	echo ##########################
	echo
	echo You CANNOT use the MasmBasic library
	echo with the old ml.exe version 6.14,
	echo because in 1999 nobody knew SSE2...
	echo
	echo By far the best solution:
	echo 1. rename \Masm32\bin\ml.exe to mlv614.exe
	echo 2. download JWasm from
	echo http://sourceforge.net/projects/jwasm/
	echo 3. extract JWasm.exe and rename to \Masm32\bin\ml.exe
	echo
	echo ##########################
	.err
  endif
ENDM
MbWinVersion MACRO
  uselib ntdll
  push eax
  mov eax, esp
  push eax
  mov edx, esp
  push eax
  invoke RtlGetNtVersionNumbers, edx, eax, esp
  pop edx		; build in dx
  pop eax		; major
  pop ecx		; minor
  EXITM <eax>
ENDM
ComCtl32$ MACRO arg
Local ccFmt$
  ifndef cc32vinfo
	.DATA
	cc32vinfo DLLVERSIONINFO <DLLVERSIONINFO, ?>
	.DATA?
	cc32info$	db 20 dup(?)
	.CODE
  endif
  pushad
  xchg rv(LoadLibrary, "ComCtl32"), esi
  .if esi
	mov ecx, rv(GetProcAddress, esi, "DllGetVersion")
	.if ecx
		push offset cc32vinfo
		call ecx
	.endif
	invoke FreeLibrary, esi
  .endif
  popad
  if @InStr(1, <  &arg>, <!%3f>)
	.DATA
	ccFmt$ db arg, 0
	.CODE
	exitm <Str$(OFFSET ccFmt$, cc32vinfo.dwMinorVersion/100+cc32vinfo.dwMajorVersion)>
  else
	exitm <Str$("%3f", cc32vinfo.dwMinorVersion/100+cc32vinfo.dwMajorVersion)>
  endif
ENDM
APs equ [edi.ArrPlot]	; #### gdi+ and GUI ####
GuiId MACRO txt
  IdCt=IdCt+1
  @CatStr(<txt>, < equ >, %IdCt)
  EXITM %IdCt
ENDM
gdiPath MACRO inx
LOCAL oa
  oa = opattr inx
  if (oa eq atImmediate) or (oa eq atRegister)
	EXITM <MbSpriteTable[8*inx]>
  else
	mov eax, inx
	EXITM <MbSpriteTable[8*eax]>
  endif
ENDM
gdiStatus$ macro inx
  push edi 
  push ecx
  ExternDef GdiStatus$:BYTE
  mov edi, offset GdiStatus$
  xor edx, edx
  ifb <inx>
	push GdiSI.jjLastError
  else
	push inx
  endif
  mov al, 0
  or ecx, -1
  .Repeat
	inc edx
	.Break .if edx>stack
	repne scasb
  .Until byte ptr [edi]==al
  pop eax
  xchg eax, edi
  .if Zero?
	void Str$("Unknown error %i", edi)
  .endif
  pop ecx
  pop edi
  EXITM <eax>
ENDM
gdi MACRO argc, args:VARARG
  invGdip @SubStr(<argc>, @InStr(1, <argc>, <Gdip>)), args
ENDM
invGdip macro gpCall, args:VARARG
Local tmp$
  ifidn <args>, <#>
	call gpCall
  else
	if @InStr(1, <args>, <esp>)
		tmp$ CATSTR <## line >, %@Line, <: do not use esp as gdi+ argument ##>
		% echo tmp$
		if usedeb
		  .err
		endif
	endif
	push ecx
	invoke gpCall, args
	pop ecx
  endif
  ifndef invGdipOK
	invGdipOK=0	; >1 means show only failures
  endif
  if usedeb or invGdipOK
	if invGdipOK eq 1
		% echo gpCall args
	endif
	.if eax || invGdipOK eq 1
		pushad
		xchg eax, ecx
		tmp$ CATSTR <Print "** line >, %@Line, <, &gpCall">
		tmp$
		PrintLine At(44, Locate(y)) Spc2$, gdiStatus$(ecx), Spc4$
		popad
	.endif
  endif
ENDM

i2f macro iarg
LOCAL tmp$, oa
  if iarg LT 0
	tmp$ CATSTR <i2fx>, %(-iarg)
  else
	tmp$ CATSTR <i2f>, %iarg
  endif
  oa = opattr(tmp$)
  ife oa
	.DATA
	tmp2$ CATSTR tmp$, < REAL4 &iarg&.0>
	% tmp2$
	.CODE
  endif
  EXITM tmp$
ENDM
MakeBrush MACRO dest, colref, hatch:=<0>
  if (opattr dest) ne atMemory
	ifndef dest
		.DATA?
		dest dd ?
		.CODE
	endif
  endif
  % ifidn <dest>, <DWORD ptr [Edx]>
	lea edx, dest
	or eax, 0ff000000h
	gdi+ GdipCreateSolidFill, colref, edx
  elseifidn <colref>, <eAx>
	gdi+ GdipCreateSolidFill, colref, addr dest
  elseif @InStr(1, <colref>, <shl 24>)
	gdi+ GdipCreateSolidFill, colref, addr dest
  elseifidni <hatch>, <gdip>
	lea edx, dest
	or eax, 0ff000000h
	gdi+ GdipCreateSolidFill, colref, edx
  elseif @InStr(1, <hatch>, <HS_>)
	mov dest, rv(CreateHatchBrush, hatch, colref)
  else
	push edx
	push ecx
	invoke CreateSolidBrush, colref
	pop ecx
	pop edx
	mov dest, eax
  endif
ENDM
MakePen MACRO penName, args:VARARG
Local is, tmp$, penN$, sArrow, eArrow, pStyle, pWidth, c3$, argW$, argC$, argsL$, argsR$, argeL$, argeR$, gdiPen, isArr, isFilled
  tmp$ CATSTR <Myarg=>, <penName>
	% echo tmp$
  gdiPen=0
  isFilled=1
  % isArr INSTR <penName>, <[Edx>
  tmp$ CATSTR <NAME=>, <penName>, <, A=>, %isArr
  % echo tmp$
  pStyle equ <PS_SOLID>
  argW$ equ <1>
  push ecx
  if isArr
	push edi
	mov edi, edx
  endif
  FOR arg, <args>
	tmp$ CATSTR <arg>, <  >
	c3$ SUBSTR tmp$, 1, 3
	is INSTR <arg>, <:>
	ifidni c3$, <sta>
		gdiPen=1
		if is
			argsL$ SUBSTR <arg>, 11, is-11
			argsR$ SUBSTR <arg>, is+1
		else
			argsL$ SUBSTR <arg>, 11
		endif
	elseifidni c3$, <emp>
		isFilled=0
	elseifidni c3$, <ins>
		argIns$ SUBSTR <arg>, 7
		argIns$ CATSTR <FP4(>, argIns$, <.0)>
	elseifidni c3$, <end>
		gdiPen=1
		if is
			argeL$ SUBSTR <arg>, 9, is-9
			argeR$ SUBSTR <arg>, is+1
		else
			argeL$ SUBSTR <arg>, 9
		endif
	elseifidni c3$, <col>
		is INSTR <arg>, <shl 24>
		if is
			gdiPen=1
		endif
		argC$ SUBSTR <arg>, 4
	elseifidni c3$, <wid>
		argW$ SUBSTR <arg>, 6
	elseifidn c3$, <PS_>
		pStyle equ <arg>
	else
		ifidni <arg>, <eax>
			argC$ equ <arg>
		else
			is INSTR <arg>, <shl 24>
			if is
				gdiPen=1
				argC$ equ <arg>
			elseif opattr(arg) eq atImmediate
				argW$ equ <arg>
			else
				% echo ## MakePen: bad argument [arg]
			endif
		endif
	endif
  ENDM
  if gdiPen or isArr
	ife isArr
		@CatStr(<g@&penName=1>)
		.DATA?
		tmp$ CATSTR <penName>, <@Caps>
		% tmp$ dd ?, ?
		ifndef penName
			penName dd ?
		endif
		.CODE
	endif
	needsGdiP=1
	is INSTR argC$, <shl>
	if is
		is INSTR argC$, <shl 24>
		ife is
			tmp$ CATSTR <## line >, %@Line, <: first arg in RgbCol must be _alpha_ for Gdi+ pen ##>
			% echo tmp$
			.err
			EXITM
		endif
	endif
	if isArr
		penN$ equ <dword ptr [edi]>
		invGdip GdipCreatePen1, argC$, i2f(argW$), UnitWorld, edi
	else
		penN$ equ <penName>
		invGdip GdipCreatePen1, argC$, i2f(argW$), UnitWorld, addr penName
	endif
	ifdef argsL$
		is INSTR argsL$, <Line>
		if is
			invGdip GdipSetPenStartCap, penN$, argsL$
		else
			invGdip GdipCreateAdjustableArrowCap, i2f(argsL$), i2f(argsR$), isFilled, offset tmp$
			ifdef argIns$
				invGdip GdipSetAdjustableArrowCapMiddleInset, tmp$, argIns$	; REAL middleInset
			endif
			invGdip GdipSetPenCustomStartCap, penN$, tmp$
		endif
	endif
	ifdef argeL$
		is INSTR argeL$, <Line>
		if is
			invGdip GdipSetPenEndCap, penN$, argeL$
		else
			invGdip GdipCreateAdjustableArrowCap, i2f(argeL$), i2f(argeR$), isFilled, offset tmp$+4
			ifdef argIns$
				; usedeb=1
				invGdip GdipSetAdjustableArrowCapMiddleInset, tmp$[4], argIns$	; REAL middleInset
				; MsgBox 0, "¨", "Hi", MB_OK
			endif
			invGdip GdipSetPenCustomEndCap, penN$, tmp$[4]
		endif
	endif
	if isArr
		pop edi
	endif
  else
	ifndef penName
		.DATA?
		penName dd ?
		.CODE
	endif
	invoke CreatePen, pStyle, argW$, argC$
	mov penName, eax
  endif
  pop ecx
ENDM

.CODE	; any macro put here will be run before proc start - but code before start: cannot be executed
	TestMasmVersion
.const
; Equates and constants

emArr$ equ <( EaX)>
ifndef MbUseErrLine
	MbUseErrLine	= 0	; indicate line where runtime error occurred (+10 bytes per call)
endif
if 0
;	Do NOT change the values below - edit the include file instead
	include \masm32\MasmBasic\MbLibConstants.inc
else
  ; release version
  MbNumSlots	= 50		; # of slots (9=0....8)
  ArrInfoOffset	= 4*20+2*4*MbNumSlots
  MbMaxKBytes	= 10		; allowed size per call, ca. 8ms/MB
  MbLevels	= 2		; # of slots
  MbBufSize	= MbLevels*MbMaxKBytes*32000  ;1024		; total size to allocate
  MbBufRotate	= MbBufSize*(MbLevels-1)/MbLevels		; if start address above, rotate
  MbArrCt	= 1	; 0 is reserved for Recall special ID and QSortPtr, 1 for Files$
  MbDlevels	= 2F3A7074h
  ifndef GfMaxFiles
	GfMaxFiles	= 100
  endif
  MbMaxArrays	= 100
  ifndef MbHeapStrings
	MbHeapStrings	= 100
  endif
  MbBufferGet	PROTO
  MbBufferFix	PROTO
  MbSaveEcx =	1	; used only in Declare
  MbDword =	0
  MbReal4 =	1
  MbReal8 =	2
  MbReal10 =	3
  MbXmmR =	4
  MbXmmI =	5
  MbQword =	6
  MbST0 = 	7
  ; MbWord =	see wp: flag returned in aPass$ by ChkNum
  ; MbByte =	see bp: flag
endif
sLine=			0
signed	equ sdword ptr 
stack	equ <DWord Ptr [esp]>
sm	equ invoke SendMessage, 
LastFileName$	equ offset wfd.cFileName
; LastFileDosName$: see Exist/wExist
LastFileSize	equ wfd.nFileSizeLow
wCrLf$	equ offset wCrLf_txt
wLf$	equ offset wLf_txt
wTb$	equ offset wTab_txt
ifndef CrLf
  CrLf	equ 13,10
endif

MbEvCt=0
EndOfCode MACRO argd	; combines ExitProcess & end start
  ife MbExit
	Exit argd
  endif
  if TclCtC gt 1
	TryCatchEnd
  endif
  if MbEvCt
	GuiEnd 0
  endif
  if MbNaTiCt and 1
	echo
	echo ### check your NanoTimer calls ###
  endif
  end start
ENDM
ClearLastError MACRO
  pushad
  invoke SetLastError, 0
  popad
ENDM
HeapTest MACRO hint
Local tmp$
  pushad
  invoke HeapValidate, MbProHeap, 0, 0
  .if !eax
	ifnb <hint>
		tmp$ CATSTR <push chr$("HeapTest fails miserably in line >, %@Line, < for &hint", 13, 10)>
	else
		tmp$ CATSTR <push chr$("HeapTest fails miserably in line >, %@Line, <", 13, 10)>
	endif
	tmp$
	MbStdOut PROTO
	call MbStdOut
	INT 3
  .endif
  popad
ENDM

AlignX macro abytes	; nidud
Local xbytes
  ifndef start
	.err <## AlignX can't be used in libraries and object modules ##>
  endif
  xbytes=abytes-(($-_TEXT) and (abytes-1))
  if xbytes
	db xbytes dup(90h)
  endif
endm
Align64 equ <AlignX 64>
include \masm32\MasmBasic\Res\DualMacs.asm		; Switch_ MACRO etc

MinLampSize	= 200	; LAMP$ minimum size for judging API algos
FifRetLen	= 1600	; buffer for FindString

; Macros
;     OPATTR guide
;     Bit	Set If...
;     0	References a code label
;     1	Is a memory expression or has a relocatable data label
;     2	Is an immediate expression
;     3	Uses direct memory addressing, i.e. is an absolute memory reference
;     4	Is a register expression
;     5	References no undefined symbols and is without error
;     6	References a stack location (usually a LOCAL variable or parameter)
;     7	References an external label
;     8-10	Language type (0=no type)
		; 76543210	; use and 127 to mask external label and language bits
atMemory	= 34	; 00100010	; [edx+20], [ebx+20], [eax+edx+20], JWasm: [eax+4*eax+20], [eax+20]
atImmediate	= 36	; 00100100
atLabel	= 37	; 10100101
atOffset	= 38	; 10100110	; offset CrLf$ (immediate and mem expression)
atGlobal	= 42	; 10101010	; CrLf$, Masm: [eax+4*eax+20], [eax+20]
atRegLabel	= 43	; 10101011	; Masm: [eax+start] (Jwasm yields 37)
atRegister	= 48	; 00110000	; also xmm
atXmm	= 77	; xxxxxxxxx	; reg starting with x
atLocal	= 98	; 01100010	; [esp+20], [ebp+20]
; numerical arrays and string arrays use the same table, with strings above table[0] and numerical ...
NumArrTable equ MbArrTable	; ... structures below table[-x] ==> MbStrucTable, MbMaxArrays
StringArrHeader STRUCT	; for MbArrTable
  numEL	dd ?	; #elements used
  recHeap	dd ?	; Recall heap - the buffer that holds the file content
  numAL	dd ?	; #elements allocated
  sdim2	dd ?	; set if string array has two dimensions
  AnsiSize	dd ?
  res2	dd ?
StringArrHeader ENDS
MbNull$ equ <offset MbArrEmpty>
m2m macro M1, M2  ; modified from Masm32 - handles WORD and BYTE destinations
  if TYPE(M1) eq 4
	push M2
	pop M1
  elseif (TYPE(M1) eq REAL4) or (TYPE(M1) eq REAL8)
	ffree st(7)
	fld M1
	fstp M2
  else
	push eax
	push M2
	pop eax
	if TYPE(M1) eq WORD
		mov M1, ax
	elseif TYPE(M1) eq BYTE
		mov M1, al
	else
		% echo ## Invalid type of M1 ##
		.err
	endif 
	pop eax
  endif
ENDM
jecxz_ MACRO jmpdest
  if usedeb
	test ecx, ecx
	je jmpdest
  else
	jecxz jmpdest
  endif
ENDM
if?Single=0
If? MACRO cmparg, arg1, arg2
LOCAL iseq, isne, isge, isgt, isle, islt, isae, isab, isbeq, isbe, cL$, cM$, cR$, is, isB, lblx, hasq, mov2$, zero$, nonz$
  ifb <cmparg>
	if if?Single
		EXITM <IfOut>
	endif
	cM$ CATSTR <## line >, %@Line, <: blank If? only after 'single' comparison ##>
	.err cM$
  endif
  hasq INSTR <arg1>, <">
  mov2$ equ mov eax, arg2
  ife hasq
	hasq INSTR <arg1>, <'>
	ife hasq
		hasq INSTR <arg2>, <">
		ife hasq
			hasq INSTR <arg2>, <'>
		endif
	endif
  endif
  if hasq
	mov2$ equ mov eax, repargA(arg2)
  endif
  isB INSTR <cmparg>, < >
  ife isB
	ifndef IfOut
		.DATA?
		IfOut dd ?
		.CODE
	endif
	if?Single=1
	cL$ equ cmparg
	nonz$ equ !Zero?
	zero$ equ Zero?
	is=0
	ifdifi <cmparg>, zero$
		ifdifi <cmparg>, nonz$
			is=opattr cmparg
		endif
	endif
	if is eq atImmediate
		if cmparg
			push arg1
		else
			push arg2
		endif
	elseifidni cL$, zero$
		.if Zero?
			push arg1
		.else
			push arg2
		.endif
	elseifidni cL$, nonz$
		.if Zero?
			push arg2
		.else
			push arg1
		.endif
	else	
		cmp cL$, 0
		.if !Zero?
			push arg1
		.else
			push arg2
		.endif
	endif
	pop IfOut
	EXITM <IfOut>
  endif
  if?Single=0
  cL$ SUBSTR <cmparg>, 1, isB-1
  is INSTR isB+3, <cmparg>, < >	; eax gt ecx
  cR$ SUBSTR <cmparg>, is+1
  cM$ SUBSTR <cmparg>, isB+1, is-isB-1
  iseq INSTR cM$, <eq>
  isne INSTR cM$, <ne>
  isge INSTR cM$, <ge>
  isgt INSTR cM$, <gt>
  isle INSTR cM$, <le>
  islt INSTR cM$, <lt>
  isae INSTR cM$, <ae>
  isab INSTR cM$, <ab>
  isbeq INSTR cM$, <be>	; below or equal
  isb INSTR cM$, <bl>	; below
  ifdifi <eax>, <arg1>
	if hasq
		mov eax, repargA(arg1)
	else
		mov eax, arg1
	endif
  endif
  cmp cL$, cR$
  if iseq
	.if !Zero?
		mov2$
	.endif
  elseif isne
	.if Zero?
		mov2$
	.endif
  elseif isge
	jge lblx
	mov2$
  elseif isgt
	jg lblx
	mov2$
  elseif isle
	jle lblx
	mov2$
  elseif islt
	jl lblx
	mov2$
  elseif isab
	ja lblx
	mov2$
  elseif isae
	jae lblx
	mov2$
  elseif isbeq
	jbe lblx
	mov2$
  elseif isb
	jb lblx
	mov2$
  else
	mov2$ CATSTR <## line >, %@Line, <: invalid arg '>, <cmparg>, <' ##>
	% echo mov2$
	.err
  endif
  lblx:
  EXITM <eax>
ENDM
Div_ MACRO args
LOCAL @eAx, arg, is
  is INSTR <args>, </>
  if is
	@eax SUBSTR <args>, 1, is-1
  else
	@eax equ <eax>
  endif
  arg SUBSTR <args>, is+1
  is INSTR arg, <.>
  if is
	ifdifi @eax, <eax>
		mov eax, @eax
	endif
	push eax
	fild stack
	fld FP8(arg)
	fdiv
	fistp stack
	pop eax
  elseif (type(arg) eq REAL4) or (type(arg) ge REAL8) 
	ifdifi @eax, <eax>
		if (type(@eax) eq REAL4) or (type(@eax) ge REAL8)
			fld @eax
		else
			push @eax
			fild stack
		endif
	else
		push eax
		fild stack
	endif
	fld arg
	fdiv
	fistp stack
	pop eax
  else
	ifdifi @eax, <eax>
		mov eax, @eax
	endif
	push arg
	cdq
	idiv stack
	add esp, 4
  endif
  EXITM <eax>
ENDM
If_ MACRO args:VARARG	; If_ not eax Then inc ecx : add ecx, ...
LOCAL is, arg$, _cond$, _do$, argsLen, not$
  arg$ equ '&args'
  not$ SUBSTR arg$, 2, 4
  argsLen INSTR 2, arg$, <'>
  is INSTR arg$, <Then>
  ife is
	.err @CatStr(<*** no Then in line >, %@Line, < ***>)
  else
	_do$ SUBSTR arg$, is+5, argsLen-is-5
	ifidni not$, <not >
		_cond$ SUBSTR arg$, 6, is-7
		.if !_cond$
			_do$
		.endif
	else
		_cond$ SUBSTR arg$, 2, is-3
		.if _cond$
			_do$
		.endif
	endif
  endif
ENDM
; Read & Data
MbCtD=0		; data inserted so far
MbCtR=0		; read so far
isqd macro
local ct, is, tmp$, found
  ct=MbCtR
  found=-1
  while ct le MbCtD and found lt 0
	tmp$ CATSTR <[>, <MbData>, %ct, <]>
	is INSTR tmp$, <">
	ife is
		is INSTR tmp$, <'>
	endif
	ife is
		found=ct
	endif
	ct=ct+1
  endm
  exitm %found
ENDM
ReadH macro dest, arg
Local cd$, c1$, c3$, r2qw
  cd$ CATSTR <MbData>, %MbCtR
  c1$ SUBSTR <arg>, 1, 1
  c3$ SUBSTR @CatStr(<dest>, <   >), 1, 3
   ifidn c1$, <">
   	push edx
   	push eax
	Let dest=arg
	pop eax
	pop edx
  elseifidn c1$, <'>
   	push edx
   	push eax
	Let dest=arg
	pop eax
	pop edx
  elseifidni c3$, <xmm>
	.DATA
	r2qw QWORD arg
	.CODE
	movlps dest, r2qw
  elseifidni c3$, <f:x>
	.DATA
	r2qw REAL8 arg
	.CODE
	movlps @SubStr(<dest>, 3), r2qw
  elseifidni <arg>, emArr$
	push MbArrTable[-8]	; MbArrStrCt
	push stLastID
	call MbArrayGet
	mov dest, eax
  else
	if (opattr dest) eq atRegister
		if (arg ge -128) and (arg le 127)
			m2m dest, arg
		else
			mov dest, arg
		endif
	elseif TYPE(dest) eq QWORD
		.DATA
		r2qw QWORD arg
		.CODE
		ffree st(7)
		fld r2qw
		fstp dest
	elseif TYPE(dest) eq REAL8
		.DATA
		r2qw REAL8 arg
		.CODE
		ffree st(7)
		fld r2qw
		fstp dest
	elseif TYPE(dest) eq REAL4
		.DATA
		r2qw REAL4 arg
		.CODE
		ffree st(7)
		fld r2qw
		fstp dest
	else
		m2m dest, arg
	endif
  endif
  MbCtR=MbCtR+1
ENDM
Data MACRO args:VARARG	; use with Read
  FOR dArg, <args>
	@CatStr(<MbData>, %MbCtD, < equ !<>, <dArg!>>, < >)
	MbCtD=MbCtD+1
  ENDM
ENDM
$Data MACRO args:VARARG	; use for string data without quotes
  FOR dArg, <args>
	@CatStr(<MbData>, %MbCtD, < equ !<"&dArg"!>>, < >)
	MbCtD=MbCtD+1
  ENDM
ENDM
Read MACRO dest0:VARARG	; use with Data
LOCAL dct, rct, oa, isq, dest, tmp$
  if usedeb
	tmp$ SUBSTR <&dest0>, 1, 1
	ifidn tmp$, <?>
		tmp$ CATSTR <** read numeric array values (line >, %@Line, <)>
		% echo tmp$
	else
		echo ** read dest0 
	endif
  endif
  for arg1, <dest0>
	isq INSTR <arg1>, <$(>
	if isq
		Dim dest0
		tmp$ CATSTR @SubStr(<dest0>, 1, isq+1), <id)>
		dest = tmp$
		oa=atImmediate
	else
		isq INSTR <arg1>, <()>
		if isq
			.err <numeric arrays must be Dim'ed before>
		endif
		oa = opattr arg1
		dest equ <dest0>
	endif
	exitm
  endm
  if oa eq atImmediate
	if dest ge 0
		dct=isqd()-1
		rct=0
		push ecx
		While dct ge MbCtR
			tmp$ CATSTR <MbDat$>, %dct, < db MbData>, %dct, <, 0>
			.DATA
			tmp$
			.CODE
			tmp$ CATSTR <push offset MbDat$>, %dct
			tmp$
			dct=dct-1
			rct=rct+1
		ENDM
		MbCtR=MbCtR+rct
		xor ecx, ecx
		.Repeat
			push ecx
			push dest
			call MbArrayGet
			; no push offset MbLsx
			push 80000001h
			call MbPrint
			inc ecx
		.Until ecx>=rct
		xchg eax, ecx
		pop ecx
	else
		.err @CatStr(<## line >, %@Line, <: use ArraySet for numeric arrays ##>)
	endif
  else
	FOR dArg, <dest0>
		% ReadH @CatStr(dArg, <, >, <MbData>, %MbCtR)
	ENDM
  endif
ENDM
StosChar MACRO arg
  ifb <arg>
	.err <where's da char?>
  else
	mov al, arg
	stosb
  endif
ENDM

DefCon macro name, val
  ifndef name
	ifidn <">, @SubStr(<val>, 1, 1)
		.DATA
		name db val, 0
	else
		name equ val
	endif
  endif
ENDM
@Imm macro arg
LOCAL oa, c1$
  oa = opattr arg
  if oa eq atImmediate
	c1$ SUBSTR <arg>, 1, 1
	ifidn c1$, <">
		oa=0
	elseifidn c1$, <'>
		oa=0
	endif
  endif
  EXITM %(oa eq atImmediate)
ENDM

@Lower$ macro txIn
LOCAL txOut, is
  txOut equ <>
  FORC arg, <txIn>
	is INSTR <ABCDEFGHIJKLMNOPQRSTUVWXYZÄÖÜ>, <arg>
	if is
		txOut CATSTR txOut, @SubStr(<abcdefghijklmnopqrstuvwxyzäöü>, is, 1)
	else
		txOut CATSTR txOut, <arg>
	endif
  ENDM
  EXITM txOut
ENDM

@Trim$ macro txIn
LOCAL ct, posL, posR, tmp$
  ct=0
  posL=0
  % FORC arg, <txIn>
	ct=ct+1
	ifidn <arg>, < >
		ifndef posR
			posL=ct
		endif
	elseifidn <arg>, < >	; Ascii 255
		ifndef posR
			posL=ct
		endif
	elseifidn <arg>, <	>	; Tab
		ifndef posR
			posL=ct
		endif
	else
		posR=ct
	endif
  ENDM
  % tmp$ SUBSTR <txIn>, posL+1, posR-posL
  EXITM tmp$
ENDM

raCt =	1
raMax =	100	; repeated strings max count
raFound =	0
raSize =	0
raWide =	0
repargW macro args:VARARG
  raWide = 1
  EXITM <repargA(args)>
ENDM
repargA macro arg:REQ
LOCAL ct, quot, rastr, ralbl, is, isR, url$, oa, tmp$, argWide, isa$, qu$
  isa$ CATSTR <arg>, <...>
  isa$ SUBSTR isa$, 1, 4
  rastr SUBSTR <arg>, 1
  is INSTR rastr, <">
  ife is
	is INSTR rastr, <'>
	ife is
		is=1
	endif
  endif
  quot SUBSTR rastr, is, 1	; takes care of blanks after At()
  ct = 0
  ifidn quot, <">
	ct = raCt
  elseifidn quot, <'>
	ct = raCt
  elseifdifi quot, <a>
	oa = opattr arg	; no good for addr string
	if oa eq atImmediate
		ct = raCt	; prt 9, 13, 10, i.e. tab, cr, lf
	endif
  endif
  if ct
	if ct gt raMax	; it gets really slow for many loops
		ct = raMax
	elseif @SizeStr(<arg>) le 4	; up to 4 bytes, the macro won't work
		ct = 0
		if @SizeStr(<arg>) eq 2
				raWide = 0
				EXITM <offset MbArrEmpty>	; Let eax=""
		endif
	endif
	While ct gt 0
		rastr CATSTR <ra_str>, %ct
		tmp$ equ <arg>
		ifidn rastr, tmp$
				raFound = raFound + 1
				ralbl CATSTR <ra_lbl>, %ct
				ct = 0
		endif
		ct=ct-1
	ENDM
	if ct ge 0
		raCt=raCt+1
		tmp$ CATSTR <ra_str>, %raCt, < equ !<arg!>>
		tmp$
		ralbl CATSTR <ra_lbl>, %raCt
		.DATA
		align 4
		isa$ SUBSTR <arg>, 1
		is INSTR isa$, <[url>	; escape for filenames
		if is
			tmp$ SUBSTR isa$, 1, is-1
			% qu$ SUBSTR <arg>, 1, 1
			ifidn qu$, <">
				qu$ equ <",34,">
			else
				qu$ equ <">
			endif
			While is
				isR INSTR is+3, isa$, <]>
				url$ SUBSTR isa$, is+5, isR-is-5
				tmp$ CATSTR tmp$, <!<A HREF=>, qu$, url$, qu$, <!>>
				isE INSTR isR, isa$, <[/url]>
				clk$ SUBSTR isa$, isR+1, isE-isR-1
				tmp$ CATSTR tmp$, clk$, <!</A!>>
				is INSTR isE+3, isa$, <[url>
				if is
				  clk$ SUBSTR isa$, isE+6, is-isE-6
				else
				  clk$ SUBSTR isa$, isE+6
				endif
				tmp$ CATSTR tmp$, clk$
			ENDM
		else
			tmp$ equ <arg>
		endif
		is INSTR <arg>, <°\">	; escape for filenames
		While is
		    strL SUBSTR tmp$, 1, is-1
		    strR SUBSTR tmp$, is+2
		    tmp$ CATSTR strL, <", 34, >, strR
		    is INSTR tmp$, <°\">
		ENDM
		ralbl db tmp$, 0
		raSize=sizeof ralbl-1
		.CODE
	endif
	if raWide
		.DATA?
		align 2
		argWide dw SIZEOF ralbl dup(?)
		.CODE
		push edx
		push offset ralbl
		push offset argWide
		call wDataP
		pop edx
		raWide = 0	; clear Unicode flag
		EXITM <OffSet argWide>	; OffSet indicates wChr$
	endif
	EXITM <offset ralbl>
  else			; else return arg
	raWide = 0
	ifidni isa$, <addr>
		tmp$ SUBSTR rastr, is+5
		oa = (opattr tmp$) AND 127
		if (oa eq atLocal) or (oa eq atMemory)
			lea edx, tmp$
			EXITM <edx>
		else
			ife oa
				% echo FoREF tmp$
				ExternDef tmp$:BYTE	; enable forward ref
			endif
			tmp$ CATSTR <offset >, tmp$
			EXITM tmp$
		endif
	else
		is INSTR <arg>, <Use_>
		if is eq 1
			EXITM Cat$(arg)	; e.g. MsgBox Left$(esi)...
		else
			EXITM <arg>
		endif
	endif
  endif
ENDM
pmArg MACRO args:VARARG
Local isP, isM, is
  isP INSTR <args>, <+>
  isM INSTR <args>, <->
  if isP or isM
	is=isP
	ife is
		is=isM
	endif
	mov edx, @SubStr(<args>, 1, is-1)
	if isP
		add edx, @SubStr(<args>, is+1)
	else
		sub edx, @SubStr(<args>, is+1)
	endif
	exitm <edx>
  else
	% echo ** no need to use pmArg for args **
	exitm <args>
  endif
ENDM
MbXms macro slotarg
  if useXmSave
	MbXSlot=0
	ifidni <slotarg>, <s2>
		MbXSlot=512
	endif
	ExternDef MbXs:DWORD
	fxsave MbXs[MbXSlot]
  endif
ENDM

MbXmr macro
  if useXmSave
	fxrstor MbXs[MbXSlot]
  endif
ENDM

MbInfo$ macro dummyarg
  EXITM Cat$("MbNumSlots"+Str$("\t%i\n", MbNumSlots)+"MbMaxKBytes"+Str$("\t%i\n", MbMaxKBytes)+"MbLevels  "+Str$("\t%i\n", MbLevels)+"MbBufSize"+Str$("\t%i\n", MbBufSize)+"MbBufRotate"+Str$("\t%i", MbBufRotate))
ENDM
; avoids JWasm warning
exit macro optional_return_value:=<0>
        invoke ExitProcess, optional_return_value
ENDM

; ---------------- start of Dlg macros ------------------
pDlgEsi equ <MbFlags[16]>
DlgUnits equ <MbFlags[20]>
dcButton=	0080h
dcEdit=	0081h
dcStatic=	0082h
dcListbox=	0083h
dcScrollbar=	0084h
dcCombobox=	0085h
dcScaleX=	1000
dcScaleY=	1000
; plus "SysListView32", "RichEdit20a", "richedit20w", etc
DlgDefStyle=WS_OVERLAPPED or WS_SYSMENU or DS_CENTER
DlgTestStyle=0	; set WS_BORDER to see the boundaries
DlgOwner equ <0>
DlgPosY=0	; allows vertical scaling

MbDLG STRUCT
  mbPMem	dd ?	; start of memory template
  mbIcon	dd ?	; IDI_xx
  dh_ALL	dd ?	; hook the complete MbDlgP
  dh_INITDIALOG	dd ?	; optional WM_INITDIALOG handler
  dh_COMMAND	dd ?	; optional WM_COMMAND handler
  dh_CLOSE	dd ?	; optional WM_CLOSE handler
  dh1	dd ?	; handle #1
  dh2	dd ?	; handle #2
  dh3	dd ?
  dh4	dd ?
  dhRich	dd ?	; handle #6
  dlgRetEax	dd ?	; user may set this value to return e.g. brushes
  mbRetEax	dd ?
  mbRetEbx	dd ?
  mbRetEcx	dd ?
  mbRetEdx	dd ?
MbDLG ENDS

TestInitCC macro	; check if InitCommonControls has been set
  ifndef dcICC
	dcICC=1
	push ecx
	invoke InitCommonControls
	invoke GetDialogBaseUnits
	sar eax, 16
	push eax
	invoke GetSystemMetrics, SM_CYCAPTION	; big on Win7
	shl eax, 3
	cdq
	div stack
	shl eax, 16	; hiword is affected
	mov DlgUnits, eax
	pop eax
	pop ecx
  endif
ENDM
DlgDefine MACRO dlgTitle, posX, posY, width, height, dlgStyle:=<DlgDefStyle>, fntSize:=<12>, fntName:=<"Arial">
  DlgCCt=0		; reset #controls
  DlgEdCt=0		; reset #edit controls
  DlgIdCt=80		; set start ID
  DlgWidth=width
  DlgHeight=height
  DlgThisIcon=IDI_ASTERISK
  if DlgHeight LT 0
	DlgRows=-DlgHeight	; set the expected #rows
	DlgHeight=14*DlgRows+7
  endif
  DlgRich=0
  DlgDefY=-1
  if (opattr fntSize) eq atImmediate
	DlgFontH=fntSize
  else
	DlgFontH=12
  endif
  if DlgFontH lt 0
	DlgFontH=-DlgFontH
  endif
  DlgInitFontH=DlgFontH
  DlgFontH=12+DlgFontH/10
  push esi
  push edi 		; save regs above ebp - we have no args
;  push ecx: see mbRetEcx
  push ebp		; create a frame
  mov ebp, esp	; see leave below
  lea esi, [ebp-128]	; 32 dwords for MbDLG and for storing IDs as WORDs
  push repargW(dlgTitle)	
  pop edi
  push ecx			; save ecx
  push fntSize		; and font size
  invoke VirtualQuery, esi, esi, MEMORY_BASIC_INFORMATION	; uses MbDLG space
  mov eax, [esi.MEMORY_BASIC_INFORMATION.AllocationBase]
  pop edx			; before the stack
  pop ecx			; gets cleared
  add eax, 10000h	; guard pages (minimum Win7-32 is 5350h)
  .Repeat			; note that stack is usually 100000h; change e.g. with opt_DebugL /stack:0x200000
	push 0	; 1-2 ms for normal stacksize
  .Until esp<=eax
  mov [esi.MbDLG.mbRetEax], edi	; save edx for setting font size
  mov [esi.MbDLG.mbRetEbx], ebx	; save ebx for SetGlobals
  mov [esi.MbDLG.mbRetEcx], ecx	; save ecx for use in DlgControl
  mov [esi.MbDLG.mbRetEdx], edx	; save edx for setting font size
  mov edi, esp		; stack is DWORD aligned, so is edi now
  mov [esi.MbDLG.mbPMem], edi	; initial pointer, e.g. for storing count in [edi+8]
  mov DWORD PTR [edi+0],  DS_SETFONT or WS_VISIBLE or dlgStyle
  mov DWORD  PTR [edi+10],  posX or 10000h*posY
  TestInitCC
  mov eax, width or 10000h*DlgHeight
  add eax, DlgUnits
  mov DWORD  PTR [edi+14], eax	; width or 10000h*(DlgHeight+caption)
  ifndef MbDlgAux
	jmp MbDlgAuxEnd
	MbDlgAux:
		push ecx
		mov ecx, stack[8]
		add eax, wLen(ecx)
		push eax
	add edi, 22
		invoke MbCopy, edi, ecx, eax
		and dword ptr [eax], 0
		lea edi, [eax+2]		; Unicode strings added here, so align 2 not needed
		pop eax
		pop ecx
		retn 4
	MbDlgAuxEnd:
  endif
  push [esi.MbDLG.mbRetEax]	; dlgTitle
  call MbDlgAux
  if (opattr fntSize) eq atImmediate
	mov WORD PTR [edi], fntSize
  else
	mov edx, [esi.MbDLG.mbRetEdx]
	mov WORD PTR [edi], dx
  endif
  sub edi, 20	; compensate add edi, 22
  push repargW(fntName)
  call MbDlgAux
  mov ecx, [esi.MbDLG.mbRetEcx]
ENDM

DlgPc MACRO arg, isH:=<0>		; helper mac: 12.3% -> 123/1000
LOCAL is, tmp$
  is INSTR <arg>, <.>
  if is
	tmp$ CATSTR @SubStr(<arg>, 1, is-1), @SubStr(<arg>, is+1, 1)
	if isH
		; 5*DlgInitFontH/3-20 is better for 48 pt caption
		is=tmp$*(DlgHeight-2*DlgDefY+5*DlgInitFontH/6-11)/dcScaleY 	; best for 22 pt caption
	else
		is=tmp$*(DlgWidth-2*DlgDefY+DlgInitFontH/3-7)/dcScaleX	; 6 better for Win7
	endif
	EXITM %is
  else
	EXITM <arg>
  endif
ENDM
DlgControl MACRO ctrlType, szText, dstyle, posX1, posY1, width, height, ctlID, tooMany
LOCAL ctrlHt, xHt, c1$, c5$, tmp$, posY, posX, dsInt
  if DlgDefY lt 0
	DlgDefY=posX1	; set upper margin based on left margin
  endif
  ifnb <tooMany>
	% echo ## Too many parameters for szText ##
	.err
  endif
  posX=DlgPc(posX1)		; allows "MyX+3"
  posY=DlgPc(posY1, 1)
  ifb <width>
	ctrlWd=DlgWidth-2*posX-3
  else
	ctrlWd=DlgPc(width)
  endif
  ifb <height>
	ctrlHt=DlgFontH-1
  else
	ctrlHt=DlgPc(height, 1)
  endif
  if posY lt 0
	ifndef DlgRows
		tmp$ CATSTR <## line >, %@Line, <: rows as negative dlg_height needed ##>
		% echo tmp$
		.err
		EXITM
	endif
	posY=(DlgHeight-2*DlgDefY+DlgInitFontH-10+DlgPosY)*(-1-posY)/DlgRows+DlgDefY
  endif
  ifb <ctlID>
	DlgIdCt=DlgIdCt+1
  else
	DlgIdCt=ctlID
  endif
  c1$ SUBSTR <ctrlType>, 1, 1
  ifdif c1$, <">
	if ctrlType eq dcStatic
		xHt=DlgFontH/4
		posY=posY+xHt
		ctrlHt=ctrlHt-xHt
	endif
	if ctrlType eq dcEdit
		if DlgIdCt lt 0
			.err <negative IDs not allowed, sorry ##>
		endif
		if DlgEdCt lt (128-MbDLG-4)/2
			mov WORD PTR [esi+MbDLG+2*DlgEdCt], DlgIdCt
		endif
		DlgEdCt=DlgEdCt+1
	endif
  endif
  DlgCCt=DlgCCt+1
  add edi, 3
  and edi, -4	; align on DWORD boundary
  mov DWORD PTR [edi+0],  WS_VISIBLE or WS_CHILD or dstyle or DlgTestStyle
;  mov DWORD PTR [edi+4],  WS_EX_CLIENTEDGE
  mov DWORD  PTR [edi+8],  posX or 10000h*posY
  mov DWORD  PTR [edi+12], ctrlWd or 10000h*ctrlHt
  mov DWORD  PTR [edi+16], DlgIdCt or 0FFFF0000h
  ifidn c1$, <">
	c5$ SUBSTR <ctrlType>, 1, 5
	ifidni c5$, <"rich>
		DlgRich=1
		ifndef DlgRichDLL
			if @InStr(1, <ctrlType>, <50>)
				DlgRichDLL equ Chr$("MsftEdit.dll")	; RichEdit50W
			else
				DlgRichDLL equ "RichEd20.DLL"	; RichEdit20W
			endif
		endif
		if DlgEdCt lt (128-MbDLG-4)/2
			mov WORD PTR [esi+MbDLG+2*DlgEdCt], DlgIdCt
		endif
		DlgEdCt=DlgEdCt+1
	endif
	push eax
	sub edi, 4	; reposition: we want 18, and MbDlgAux adds 22
	push repargW(ctrlType)	; SysListView32
	call MbDlgAux
	pop eax
	sub edi, 22  	; works fine with "edit" (but no Dlg$ for "edit", by design)
  else
	mov DWORD  PTR [edi+20], ctrlType
	if ctrlType eq dcStatic
		dsInt=dstyle
		if (dsInt and SS_BITMAP) eq SS_BITMAP or (dsInt and SS_ICON) eq SS_ICON
			if DlgEdCt lt (128-MbDLG-4)/2
				push ecx
				mov ecx, edi	; get current pointer
				sub ecx, [esi.MbDLG.mbPMem]	; subtract start of template to get offset
				shl ecx, 16	; move to hiword
				or cx, -DlgIdCt	; add negative ID
				if (dstyle and SS_ICON) eq SS_ICON
						and ch, 10111111b			; clear bit 14
				endif
				mov [esi+MbDLG+2*DlgEdCt], ecx	; -DlgIdCt in loword, offset in hiword
				pop ecx
				DlgEdCt=DlgEdCt+1
			endif
			DlgEdCt=DlgEdCt+1
		endif
	endif
  endif
  ifidn <szText>, <"">
	push offset MbArrEmpty
  elseifidn <szText>, <( EdX)>	; ????
	.err
	push edx
  else
	push repargW(szText)
  endif
  call MbDlgAux
  nops 8
  inc edi
  inc edi
ENDM
DlgIcon MACRO idiXX
  DlgThisIcon=idiXX
ENDM
DlgShow MACRO
  mov edi, [esi]
  mov DWORD  PTR [edi+8],  DlgCCt	; #controls
  MbDlgP PROTO :DWORD,:DWORD,:DWORD,:DWORD
  Dim Dlg$(new:127)	; predefined in MB.inc, ID3
  mov pDlgEsi, esi
  mov [esi.MbDLG.mbIcon], DlgThisIcon	; time to define the icon
  if DlgRich
	invoke LoadLibrary, DlgRichDLL
	mov [esi.MbDLG.dhRich], eax
  endif
  invoke DialogBoxIndirectParamW, rv(GetModuleHandle, 0), [esi], DlgOwner, MbDlgP, esi
  if MbUseErrLine
	.if eax==-1
		MsgBox 0, Str$("DialogBoxIndirectParamW\nfailed miserably in line %i", @Line) , "Dlg error:", MB_OK
	.endif
  endif
  if DlgRich
	invoke FreeLibrary, [esi.MbDLG.dhRich]
  endif
  leave
;  pop ecx
  pop edi
  mov eax, [esi.MbDLG.mbRetEax]
  mov ecx, [esi.MbDLG.mbRetEcx]
  mov edx, [esi.MbDLG.mbRetEdx]
  pop esi
;  no ret - it' s a macro
ENDM

DlgHandler MACRO pHandler, wm_x		; DlgHandler MyLvInit [, WM_INITDIALOG]
LOCAL ins, tmp$
  ifb <wm_x>
	mov [esi.MbDLG.dh_ALL], pHandler
  else
	ins INSTR <wm_x>, <WM_>
	tmp$ CATSTR <MbDLG.dh>, @SubStr(<wm_x>, 3)
	if ins ne 1
		.err <## DlgHandler: wm_x is not a valid message ##>
	else
		mov [esi.tmp$], pHandler
	endif
  endif
ENDM
; ---------------- end of dialog macros ------------------
ifndef RTL_OSVERSIONINFOEXW
	RTL_OSVERSIONINFOEXW STRUCT
	dwOSVersionInfoSize	ULONG ?
	dwMajorVersion	ULONG ?
	dwMinorVersion	ULONG ?
	dwBuildNumber	ULONG ?
	dwPlatformId	ULONG ?
	szCSDVersion	WCHAR 128 dup(?)
	wServicePackMajor	USHORT ?
	wServicePackMinor	USHORT ?
	wSuiteMask	USHORT ?
	wProductType	UCHAR ?
	wReserved 	UCHAR ?
	RTL_OSVERSIONINFOEXW ENDS
endif
ifndef NoMbVariant
  VARTYPE typedef word
  VARIANT struct	; see oaidl.h
  vt	VARTYPE ?	; VARTYPE: wtypes.h says unsigned word
  wReserved1	dw ?
  wReserved2	dw ?
  wReserved3	dw ?
  union
  bstrVal	dd ?
  pintVal	dd ?
  pvRecord	dd ?	; add whatever you need..,
  ends
  VARIANT	ends
IUnknown STRUCT
  QueryInterface	dd ?
  AddRef	dd ?
  Release	dd ?
IUnknown ENDS 
IWebBrowserVtbl STRUCT
  wbUnknown IUnknown <>
  GetTypeInfoCount dd ?
  GetTypeInfo	dd ?
  GetIDsOfNames	dd ?
  invokeX	dd ?	; X to avoid a name conflict
  GoBack	dd ?
  GoForward	dd ?
  GoHome	dd ?
  GoSearch	dd ?
  Navigate	dd ?	; Flags, TargetFrameName, PostData, Headers
  Refresh	dd ?
  Refresh2	dd ?
  Stop	dd ?
  get_Application	dd ?
  get_Parent	dd ?
  get_Container	dd ?
  get_Document	dd ?
  get_TopLevelContainer	dd ?
  get_Type	dd ?
  get_Left	dd ?
  put_Left	dd ?
  get_Top	dd ?
  put_Top	dd ?
  get_Width	dd ?
  put_Width	dd ?
  get_Height	dd ?
  put_Height	dd ?
  get_LocationName	dd ?
  get_LocationURL	dd ?
  get_Busy	dd ?
  Quit	dd ?
  ClientToWindow	dd ?
  PutProperty	dd ?
  GetProperty	dd ?
  get_Name	dd ?
  get_HWND	dd ?
  get_FullName	dd ?
  get_Path	dd ?
  get_Visible	dd ?
  put_Visible	dd ?
  get_StatusBar	dd ?
  put_StatusBar	dd ?
  get_StatusText	dd ?
  put_StatusText	dd ?
  get_ToolBar	dd ?
  put_ToolBar	dd ?
  get_MenuBar	dd ?
  put_MenuBar	dd ?
  get_FullScreen	dd ?
  put_FullScreen	dd ?
  Navigate2	dd ?
  QueryStatusWB	dd ?
  ExecWB	dd ?
  ShowBrowserBar	dd ?
  get_ReadyState	dd ?
  get_Offline	dd ?
  put_Offline	dd ?
  get_Silent	dd ?
  put_Silent	dd ?
  get_RegisterAsBrowser	dd ?
  put_RegisterAsBrowser	dd ?
  get_RegisterAsDropTarget	dd ?
  put_RegisterAsDropTarget	dd ?
  get_TheaterMode	dd ?
  put_TheaterMode	dd ?
  get_AddressBar	dd ?
  put_AddressBar	dd ?
  get_Resizable	dd ?
  put_Resizable	dd ?
IWebBrowserVtbl ENDS
endif

CoInvoke MACRO pInterface:REQ,Method:REQ,args:VARARG
LOCAL is, ct, ciPush$, tmp$, tmpAddr$, errEdx$
  ct=0
  ciPush$ equ <>
  FOR arg, <args>
	ct=ct+1
	ciPush$ CATSTR <arg>, <#>, ciPush$
  ENDM
  ciPush$ CATSTR ciPush$, < >
  WHILE ct
  	ct=ct-1
	is INSTR ciPush$, <#>
	tmp$ SUBSTR ciPush$, 1, is-1
	tmpAddr$ CATSTR tmp$, <123>	; addr
	tmpAddr$ SUBSTR tmpAddr$, 1, 4
	ifidni tmpAddr$, <addr>
		errEdx$ CATSTR tmp$
		tmp$ SUBSTR ciPush$, 5, is-5
		lea edx, tmp$
		push edx
	else
		ifidni tmp$, <edx>
			ifdef errEdx$
				% echo ### edx overwritten by errEdx$ ###
				.err
			endif
		endif
		push tmp$
	endif
	ciPush$ SUBSTR ciPush$, is+1
  ENDM
  ifdifi <pInterface>, <eax>
	mov eax, pInterface
  endif
  push eax
  mov eax, [eax]
  call dword ptr [eax+Method]	; Method=4, 8, ...
ENDM

AsmHx$ macro str1
LOCAL isHex, gp$
  gp$ SUBSTR str1, 1, 1
  isHex INSTR <abcdefABCDEF>, gp$
  if isHex
	gp$ CATSTR <0>, str1, <h>
  else
	gp$ CATSTR str1, <h>
  endif
  EXITM gp$
ENDM

GuidFromString MACRO strarg	; chokes with JWasm 2.08
LOCAL is1, is2, gu$, part$
  is1 INSTR <strarg>, <">
  ife is1
	is1 INSTR <strarg>, <{>
  endif
  is2 INSTR <strarg>, <->
  part$ SUBSTR <strarg>, is1+1, is2-is1-1
  gu$ CATSTR <GUID !<>, AsmHx$(part$), <, >
  REPEAT 2
	is1=is2
	is2 INSTR is2+1, <strarg>, <->
	part$ SUBSTR <strarg>, is1+1, is2-is1-1
	gu$ CATSTR gu$, AsmHx$(part$), <, >
  ENDM
  part$ SUBSTR <strarg>, is2+1, 2
  gu$ CATSTR gu$, <!<>, AsmHx$(part$), <, >
  part$ SUBSTR <strarg>, is2+3, 2
  gu$ CATSTR gu$, AsmHx$(part$), <, >
  is1 INSTR is2+1, <strarg>, <->
  REPEAT 5
	part$ SUBSTR <strarg>, is1+1, 2
	gu$ CATSTR gu$, AsmHx$(part$), <, >
	is1=is1+2
  ENDM
  part$ SUBSTR <strarg>, is1+1, 2
  gu$ CATSTR gu$, AsmHx$(part$), <!>!>>
  EXITM gu$
ENDM

GuidsEqual MACRO MbGu1:REQ, MbGu2:REQ
LOCAL oa1, oa2, tmp$
  oa1 = OPATTR MbGu1
  oa2 = OPATTR MbGu2
  push eax
  if TYPE(MbGu1) eq GUID
	movups xmm0, MbGu1
  elseif TYPE(MbGu1) eq DWORD
	if oa1 eq atRegister
		movups xmm0, OWORD PTR [MbGu1]
	else
		mov eax, MbGu1
		movups xmm0, OWORD PTR [eax]
	endif
  elseif oa1 eq atOffset
	mov eax, MbGu1
	movups xmm0, OWORD PTR [eax]
  elseif TYPE(MbGu1) eq 16	; workaround for JWasm 2.08
	movups xmm0, MbGu1
  else
	.err
  endif
  if TYPE(MbGu2) eq GUID
	movups xmm1, MbGu2
  elseif TYPE(MbGu2) eq DWORD
	if oa2 eq atRegister		; offset in reg32
		movups xmm1, OWORD PTR [MbGu2]
	else
		mov eax, MbGu2
		movups xmm1, OWORD PTR [eax]
	endif
  elseif oa2 eq atOffset
	mov eax, MbGu2
	movups xmm1, OWORD PTR [eax]
  elseif TYPE(MbGu2) eq 16	; JWasm
	movups xmm1, MbGu2
  else
	.err
  endif
  pcmpeqb xmm0, xmm1
  pmovmskb eax, xmm0	; set byte mask in eax
  inc ax
  pop eax
  EXITM <Zero?>
ENDM
MbOle=0
Ole$ MACRO strArg:VARARG	; input ANSI, returns BSTR
  MbOle=1
  EXITM wChr$(strArg)
ENDM
if 0	; source
	Both LPOLESTR and BSTR are typedefs of 'unsigned short*'. A BSTR uses four
	bytes before the pointer to indicate its size, and therefore needn't be zero
	terminated. An LPOLESTR typically is zero terminated. A BSTR must always be
	allocated using SysAllocString and freed using SysFreeString (at least if
	you want to be interoperable with COM components)
	
	The real difference is that LPOLESTR is a typedef used by OLE, and BSTR is a
	typedef used by COM. If you interact with COM components, either by being a
	COM component or by consuming one, you should use BSTR in combination with
	SysAllocString/SysFreeString. BSTR is also the string type used by Visual
	Basic 4, 5 and 6.
endif
uChr$ MACRO args:VARARG	; UTF8->wide
  push repargA(<args>)
  call MbwRec
  EXITM <eax>
ENDM

wChr$ MACRO args:VARARG
LOCAL argByte, argWide, oa, arg1, is
  FOR arg1, <args>
	oa = opattr arg1
	EXITM
  ENDM
  if @InStr(1, <args>, <Use_mov>)
	arg1 equ Cat$(args)
	oa = -127
  else
	is INSTR <args>, <(>
	if is eq 1	; must be wChr$((reg32))
		ifndef MbwChr4
			.DATA?
			MbwChr4 dd ?	; hibyte of eax should be zero
			.CODE
		endif
		mov dword ptr MbwChr4, args	; wPrint wChr$((eax)) is allowed
		EXITM <offset MbwChr4 >	; for ptr to buffer use wChr$(eax)
	endif
  endif
  push edx		; save a reg32
  if (oa eq atImmediate) or (oa eq 0)	; ml needs the zero
	.DATA
	argByte	db args, 0
	.DATA?
	align 2
	if MbOle
		dd ?
	endif
	argWide dw SIZEOF argByte dup(?)
	.CODE
	if @InStr(1, <args>, <0>)
		push esi
		push edi
		mov esi, offset argByte
		mov edi, offset argWide
		push eax
		xor eax, eax
		.Repeat
			lodsb
			stosw
		.Until esi>=offset argByte+sizeof argByte-1
		pop eax
		pop edi
		pop esi
	else
		push offset argByte
		push offset argWide
		call wDataP		; returns end of buffer in edx
	endif
	if MbOle
		MbOle=0
		mov dword ptr argWide[-DWORD], 2*SIZEOF argByte-2
	endif
	pop edx
	EXITM <OffSet argWide>	; OffSet indicates wChr$, used in Launch
  else
	if oa eq -127
		push arg1		; push cat$
	else
		push args		; push src reg or global var
	endif
	call MbBufferGet
	if MbOle
		add eax, DWORD
	endif
	push eax		; dest
	call wDataP
	push 1			; new slot please
	push edx
	call MbBufferFix	; returns buffer start
	if MbOle
		MbOle=0
		add dword ptr [edx], DWORD	; correct address and
		sub dword ptr [edx+4], DWORD	; len in slot
		mov edx, [edx+4]	; len
		mov [eax], edx	; BSTR prefix
		add eax, DWORD
	endif
	pop edx
	EXITM <( eAx)>
  endif
ENDM
NoClByte	equ <"#">
CL$ MACRO argnum:=<127>	; mov eax, CL$() yields all args
  ifidn <argnum>, <?>
	push 125
  else
	push argnum
  endif
  call MbGetCL
  ifidn <argnum>, <?>
	mov eax, [esp-4]
	sub eax, 125
	not eax
	EXITM <eax>	; argcount
  else
	EXITM emArr$
  endif
ENDM

wCL$ MACRO argnum:=<127>		; mov eax, wCL$()
LOCAL argFound, NoArg
  push esi
  push edi
  push ecx
  ifidn <argnum>, <?>
	push 127
  else
	push argnum	; see dword ptr [esp+4]
  endif
  call GetCommandLineW
  xchg esi, eax
  call MbBufferGet
  push eax
  xor ecx, ecx
  xor eax, eax		; allow cmp eax, xx instead of cmp ax
  .Repeat
	pop edi	; aka mov edi, [esp] - fresh start for each loop
	push edi
	m2m eax, 32	; default: blank
	cdq		; shortest version of mov edx, 0
	.Repeat
		xchg eax, edx
		lodsw
		test eax, eax	; if arg has not even started, stop it
		je argFound
	.Until eax>32
	.if dword ptr [esp+4]==126	; wCL$() is 127, dec once=126, i.e. we are now on arg1
		mov ecx, esi
		dec byte ptr [esp+4+1]	; 255*255 args
	.endif
	.if eax<=39	; 34, 39
		xchg eax, edx
		lodsw
	.endif
	.Repeat
		stosw
		lodsw
	.Until !eax || eax==edx
	dec dword ptr [esp+4]	; dec argnum
  .Until Sign? || !eax
argFound:
  push 0
  pop esi
  mov [edi], esi
  .if Sign?			; correct arg found
	.if eax==edx || edx==32
		.if edx
			pop esi	; mov esi, [esp]
			push esi
		.endif
	.endif
  .else
	dec ecx
	dec ecx
	js NoArg
	void wLen(ecx)
	; cmp ah, 1	; single arg>512 bytes? unlikely... it's a relic of [esp+4]==126
	; ja NoArg
	add eax, eax	; 7441, ah=29
	pop esi	; get original dest buffer
	push eax
	push ecx	; esi = start of buffer still on stack
	push esi	; dest buffer
	call MbCopy	; invoke MbCopy, esi, ecx, eax
	and dword ptr [eax], 0
	xchg eax, edi
	push esi	; dest buffer, not zero
  NoArg:
  .endif
  .if !esi
	xchg esi, [esp]	; zero for pop eax - slow but this is a rare case
	mov edi, esi
	m2m eax, NoClByte	; Let cannot test for valid args
	stosd	; +2, len=1 char
	sub edi, 2
  .endif
  push 1			; flag increase slot
  push edi			; end address
  call MbBufferFix	; sets eax as retval and registers slot ?
  pop eax
  pop edx
  pop ecx
  pop edi
  pop esi
  ifidn <argnum>, <?>
	sub edx, 127
	not edx
	EXITM <edx>	; argcount
  else
	EXITM emArr$
  endif
ENDM

CurDir$ MACRO dummyarg	; CurDir$(0) = don't append backslash
  push ecx
  call MbBufferGet
  mov edx, 32768
  add eax, edx
  push eax
  invoke GetCurrentDirectoryW, edx, eax
  ifdifi <dummyarg>, <0>
	pop edx
	mov dword ptr [edx+2*eax], "\"
	pop ecx
	EXITM Utf8$(edx)
  else
	MbUtf8 PROTO
	call MbUtf8
	pop ecx
	EXITM emArr$
  endif
ENDM
Ini$ MACRO arg
  if @InStr(1, <arg>, <.ini>)
	.DATA?
	Ini$Data dd ?
	.CODE
	Let Ini$Data=FileRead$(arg)
	EXITM <>
  endif
  push esi
  push edi
  call MbBufferGet
  xchg eax, edi	; buffer start
  and dword ptr [edi], 0
  mov esi, Ini$Data
  .if Instr_(1, esi, repargA(arg), 4)
	xchg eax, esi
	.Repeat
		lodsb
	.Until al=="=" || !al
	.if al
		mov edx, esi
		.Repeat
			lodsb
		.Until al<=13 || al==61	; comments are allowed
		.Repeat
			dec esi
		.Until byte ptr [esi]>32
		sub esi, edx
		inc esi
		push esi
		push edx
		push edi
		call MbCopy
	.endif
  .else
	mov eax, edi	; return a Null$
  .endif
  push 1
  push eax
  call MbBufferFix
  pop edi
  pop esi
  EXITM emArr$
ENDM
MbWideExpEnv=0
wExpandEnv$ MACRO arg:REQ, longname
	MbWideExpEnv=1
	EXITM ExpandEnv$(arg, longname)
ENDM
ExpandEnv$ MACRO arg:REQ, longname	; e.g. Print ExpandEnv$("%ProgramFiles%\Microsoft Office")
	MbXms
	push ebx
	push ecx
	push 1	; flag increase slot
	call MbBufferGet
	push eax	; push a copy
	mov edx, 65536
	ifidn <longname>, <1>
		push edx	; three args for
		push eax	; GetLongPathName
		push eax
	endif
	if MbWideExpEnv
		MbWideExpEnv=0
		invoke ExpandEnvironmentStringsW, repargW(arg), eax, edx
		dec eax
		ifidn <longname>, <1>
			xchg eax, ebx
			call GetLongPathNameW	; invoke GetLongPathNameW, eax, eax, edx
			.if !eax
			    xchg eax, ebx
			.endif
		endif
		add eax, eax	; Unicode API returns chars - we need bytes
	else
		invoke ExpandEnvironmentStrings, repargA(arg), eax, edx	; check also PathUnExpandEnvStrings
		dec eax
		ifidn <longname>, <1>
			xchg eax, ebx
			call GetLongPathName	; invoke GetLongPathNameA, eax, eax, edx
			.if !eax
			    xchg eax, ebx
			.endif
		endif
	endif
	add [esp], eax	; add copied bytes to old pointer
	; push 1	; above: flag increase slot
	; push edx	; adjusted address is on stack
	call MbBufferFix	; returns ptr to start of buffer
	pop ecx
	pop ebx
	MbXmr
	EXITM emArr$	; make sure Let and Print read it properly
ENDM

ImgViewSlots=80
usedIpp=0
MbExit=0
Exit MACRO RetCode:=<0>, mode:=<500>
  ifidn <RetCode>, <0>
	MbExit=1
  endif
  if gslInit
	gsl_EXIT
  endif
  if usePython
	call Py_Finalize
  endif
  ifidni <RetCode>, <debug>	; activate for debugging
	push -111	; special ExitProcess retcode
  elseifidni <RetCode>, <dll>	; dll will not call ExProc, but some regs are needed
	pushad
  else
	push RetCode
  endif
  push -1			; erase all
  call MbArrayErase
  push -1		;; free all, including structures (MbStructErase not needed!)
  call MbStringErase	; e.g Lower$
  if usedIpp
	ExternDef GdipLoaded:DWORD
	.if GdipLoaded
		push 0	; flag clear
		push eax	; dummy
		push ImgViewSlots	; clear all
		call ImgPaintP	; invoke ImgPaintP, slot, file, handleorflag
	.endif
  endif
  ifidni <RetCode>, <debug>	; activate for debugging
	lea ecx, [edx+1]
	mov eax, gcHeapA
	.if eax!=gcHeapF
		ifidn <mode>, <box>
			sub eax, gcHeapF
			invoke MessageBox, 0, Str$(eax), Chr$("Not freed:"), MB_OK
		else
			Print Chr$(13, 10, "Alloc/Free error: ")	; rarely seen
			Print Str$(gcHeapA), "/"	
			Print Str$(gcHeapF), 13, 10
			Delay mode
		endif
	.else
		ifidn <mode>, <box>
			invoke MessageBox, 0, Str$(gcHeapA), Chr$("Debug ok, allocations:"), MB_OK
		else
			Print Str$("\nDebug OK, %i strings released", ecx)
			Delay mode
		endif
	.endif
  endif
  mov esi, offset DllTable
  m2m edi, 9
  .Repeat
	lodsd
	.if eax
		invoke FreeLibrary, eax
	.endif
	dec edi
  .Until Sign?
  ifidni <RetCode>, <dll>	; for use with DLLs
	popad
  else
	call ExitProcess	; retcode pushed above
  endif
ENDM

void MACRO args 
  @CatStr(<;>, <args>)
ENDM
EnuCt=10	; IDOK ... IDHELP=1...9
Enum MACRO args:VARARG
LOCAL arg, is, arg2, EnuP$
  EnuP$ equ <>
  for arg, <args>
	is INSTR <arg>, <#>	; set prefix
	if is
		EnuP$ SUBSTR <arg>, 2
	else
		is INSTR <arg>, <:>
		if is
			EnuCt=@SubStr(<arg>, 1, is-1)
			arg2 SUBSTR <arg>, is+1
			arg2 CATSTR EnuP$, arg2
		else
			arg2 CATSTR EnuP$, <arg>
		endif
		arg2=EnuCt
		EnuCt=EnuCt+1
	endif
  ENDM
ENDM
Enum$ MACRO inx, args:VARARG
Local tmp$, pStr
  ifdifi <inx>, <ebx>
	push ebx
	if type(inx) eq DWORD or (opattr inx) eq atImmediate
		mov ebx, inx
	else
		movzx ebx, inx
	endif
  endif
  tmp$ equ <>
  ct=0
  push ebp
  push edi
  push ecx
  mov ebp, esp
  for arg, <args>
	push arg
	tmp$ CATSTR <"&arg", 0,>, tmp$
  endm
  tmp$ CATSTR <pStr db >, tmp$, <63, 0>
  .DATA
  tmp$
  .CODE
  xor eax, eax
  mov edi, offset pStr
  or ecx, -1
  .Repeat
	pop edx
	.Break .if edx==ebx
	repne scasb
  .Until byte ptr [edi]==63	; 0, ?, 0
  xchg eax, edi
  mov esp, ebp
  pop ecx
  pop edi
  pop ebp
  ifdifi <inx>, <ebx>
	pop ebx
  endif
  EXITM <eax>
ENDM
invnzLine=0
invnz macro mainarg, args:VARARG
Local tmp$, inzLine
  invoke mainarg, args
  if usedeb
	.if !eax
		pushad
		inzLine=@Line-invnzLine
		tmp$ CATSTR <" ** invnz, line >, %inzLine, <: &mainarg failed **", 13, 10>
		% print tmp$
		popad
	.endif
  endif
ENDM
rvnz macro FuncName:REQ,args:VARARG
Local tmp$, inzLine
  the@arg equ <invoke FuncName>         ;; construct invoke and function name
  FOR var, <args>                        ;; loop through all arguments
	the@arg CATSTR the@arg,<,expand_prefix(reparg(var))>   ;; replace quotes and append the@arg
  ENDM
  the@arg
  if usedeb
	.if !eax
		pushad
		inzLine=@Line-invnzLine
		tmp$ CATSTR <" ** rvnz, line >, %inzLine, <: &FuncName failed **", 13, 10>
		% print tmp$
		popad
	.endif
  endif
  EXITM <eax>
ENDM
voidTrue MACRO args
LOCAL tmp$
  @CatStr(<;>, <args>)
  if usedeb
	.if eax!=1
		pushad
		tmp$ CATSTR <Chr$("## eax is zero in line >, %@Line, < ##")>
		PrintLine tmp$
		popad
	.endif
  endif
ENDM
voidFalse MACRO args
LOCAL tmp$
  @CatStr(<;>, <args>)
  if usedeb
	.if eax
		pushad
		tmp$ CATSTR <Chr$("## non-zero eax in line >, %@Line, < ##")>
		PrintLine tmp$
		popad
	.endif
  endif
ENDM

Fn MACRO args:VARARG
  args
  exitm <eax>
ENDM
ErrLines MACRO arg	; el blank, el off
  ifidni <arg>, <off>
	MbUseErrLine=0
  else
	MbUseErrLine=1
  endif
ENDM

SetErrLine MACRO
  if MbUseErrLine
	mov MbErrLine, @Line+1
  endif
ENDM

Delay MACRO ms:=<1>
  push ms
  MbSleep PROTO
  call MbSleep
ENDM

Sound MACRO arg
LOCAL oa
  oa INSTR <arg>, <">
  ife oa
	oa=opattr arg
  endif
  if oa eq atImmediate
	push arg
  else
	push repargA(arg)
  endif
  MbSound PROTO
  call MbSound
ENDM

Cls MACRO
  Launch "cmd.exe /c cls", (SW_HIDE), 127
ENDM

cBlack	= 0	; http://support.microsoft.com/kb/319883
cDarkBlue	= 1	; use with ConsoleColor and CgaCol()
cDarkGreen	= 2
cDarkCyan	= 3
cDarkRed	= 4
cDarkMagenta	= 5
cDarkYellow	= 6
cGray	= 7
cDarkGray	= 8
cBlue	= 9
cGreen	= 10
cCyan	= 11
cRed	= 12
cMagenta	= 13
cYellow	= 14
cWhite	= 15
cBcol	= cBlack
cFcol	= cGray
ConsoleColor MACRO fgcol:=<cFcol>, bgcol:=<cBcol>
  pushad
  MbXms S2	;; SetConsoleOutputCP comes first
  if ((opattr(fgcol)) AND 127) eq 36
	push bgcol*16+fgcol
  else
	push fgcol
	mov eax, bgcol
	shl eax, 4
	or stack, eax
  endif
  invoke GetStdHandle, STD_OUTPUT_HANDLE
  push eax
  call SetConsoleTextAttribute
  MbXmr
  popad
ENDM
CgaCol$ equ <000000AA000000AA00AAAA000000AAAA00AA0055AAAAAAAA555555FF555555FF55FFFF555555FFFF55FF55FFFFFFFFFF>
CgaCol MACRO cCol
LOCAL cc$
  cc$ SUBSTR CgaCol$, 1+6*cCol, 6
  cc$ CATSTR <0>, cc$, <h>
  EXITM cc$
ENDM
SysCol MACRO sCol
  push ecx
  push edi
  push edx
  push eax
  push esp
  push 1
  PushXPM sCol
  invoke GetDC, hWnd
  push eax
  xchg eax, edi
  call GetSystemPaletteEntries
  invoke ReleaseDC, hWnd, edi
  pop eax
  pop edx
  pop edi
  pop ecx
  EXITM <eax>
ENDM
RgbCol MACRO red, green, blue, alpha 	; invoke ..., RgbCol(red, green, blue)
  ifidn <red>, <?>
	MbCol PROTO
	call MbCol
	EXITM <eax>
  endif
  if (opattr red)+(opattr green)+(opattr blue) eq 108
	ifnb <alpha>
		EXITM <alpha+blue shl 8+green shl 16+red shl 24>	; four immediates, inversed order
	else
		EXITM <red+green shl 8+blue shl 16>	; three immediates
	endif
  elseifnb <alpha>
	ifdifi <alpha>, <eax>
		mov eax, alpha	; GdiPlus
	endif
	movzx eax, al
	mov edx, blue
	or ah, dl
	mov edx, green
	movzx edx, dl
	shl edx, 16
	or eax, edx
	mov edx, red
	movzx edx, dl
	shl edx, 24
	or eax, edx
	EXITM <eAx>

  else
	ifdifi <red>, <eax>
		mov eax, red
	endif
	movzx eax, al
	mov edx, green
	or ah, dl
	mov edx, blue
	movzx edx, dl
	shl edx, 16
	or eax, edx
	EXITM <eax>
  endif
ENDM
z$ MACRO arg
LOCAL is, tmp$
  is INSTR 1, <arg>, <Use_mov>
  if is eq 1
	push 0
	call MbGetSlotPointer
	mov eax, [edx]
	mov edx, [edx+4]
	and byte ptr [eax+edx], 0
	EXITM <eax>
  else
	tmp$ CATSTR <## Invalid argument in z$, line >, %@Line, <: >, <arg>, < ##>
	% echo tmp$
	.err
  endif
ENDM
MbSPRITE STRUCT
  spElements	dw ?	; #xy points
  spFlags	db ?	; 1=Gdi32, 0=GdiPlus
  spType	db ?	; kind of path: 0=Polygon, 1=Ellipse, 2=Bezier
  spScaleW	dd ?	; individual scaling for this
  spScaleH	dd ?	; sprite, width and height
  spBrush	dd ?	; ?? either here, or as
  spPen	dd ?	; GuiSetFill + GuiSetPen
  spAddTo	dd ?	; ex Return
  spRes	dd ?, ?	; reserved, followed by word-sized points
MbSPRITE ENDS
Enum 0:ptPoly, ptBezier, ptCurve, ptCurve2, ptClosedCurve, ptClosedCurve2, ptText, ptArc, ptRect, ptEllipse, ptPie	; bits for path types
GuiWidth	equ apStruct.apRectG.right
GuiHeight	equ apStruct.apRectG.bottom
PushXPM macro args, xpmCt:=<0>		; caution, trashes eax
LOCAL isB, isX, isP, isM, hasDot, arg2, tmp$, tmpL$, tmpR$, arg$, oa
  arg$ CATSTR <args>, <   >
  isB INSTR arg$, <]>
  isX INSTR isB+1, arg$, <*>
  isP INSTR isB+1, arg$, <+>  
  hasDot INSTR isB+1, arg$, <.>
  ife isB
	isB=1
  endif
  isM INSTR isB+1, arg$, <->
;   tmp$ CATSTR <Myarg=>, <args>, < with >, %isX, %isP, %isM, %hasDot 
;   % echo tmp$
  if hasDot
	tmpL$ SUBSTR arg$, 1, hasDot-1
	tmpR$ SUBSTR arg$, hasDot+1, 1
	tmp$ CATSTR tmpL$, tmpR$
	push tmp$
	fild stack
	ifndef XPM001
		.DATA
		XPM001 REAL4 0.001, 0.5
		.CODE
	endif
	fmul XPM001
	if xpmCt eq 1
		fimul GuiWidth
	elseif xpmCt eq 2
		fimul GuiHeight
	elseif xpmCt eq 3	; average h/w
		fild GuiWidth
		fiadd GuiHeight
		fmul XPM001[4]
		fmul
	else
		.err <## use integer ##>
	endif
	fistp stack
	if isP
		add stack, @SubStr(<args>, isP+1)
	elseif isM
		sub stack, @SubStr(<args>, isM+1)
	endif 
  elseif isX or isP or isM
	if isP
		tmp$ SUBSTR arg$, isX+1, isP-isX-1
	elseif isM
		tmp$ SUBSTR arg$, isX+1, isM-isX-1
	else
		tmp$ SUBSTR arg$, isX+1
	endif
	if isX
		arg2 SUBSTR arg$, 1, isX-1
	elseif isP
		arg2 SUBSTR arg$, 1, isP-1
	elseif isM
		arg2 SUBSTR arg$, 1, isM-1
	endif
	oa = opattr tmp$
	if oa eq atImmediate
		oa = opattr arg2
		if oa eq atImmediate
			push args
			EXITM
		endif
	endif
	ifidni arg2, <esi>
		ifdef GuiParas
			ife YouCanUseEsi
				.err @CatStr(<## You cannot use esi in line >, %@Line, < ##>)
				EXITM
			endif
		endif
	endif
	push eax		;; save reg
	if isX
		imul eax, arg2, tmp$
	elseifdifi tmp$, <eax>
		mov eax, tmp$
	endif
	if isP
		tmp$ equ arg$
		tmp$ SUBSTR tmp$, isP+1
		ifidn tmp$, <1>
			inc eax
		else
			add eax, tmp$
		endif
	elseif isM
		tmp$ SUBSTR arg$, isM+1
		ifidn tmp$, <1>
			dec eax
		else
			sub eax, tmp$
		endif
	endif
  	xchg eax, stack	;; slow but safe
  else
	push args
  endif
ENDM
PPM31=0
PushPlusMinus macro arg
LOCAL is, brOut, imm32, ppOffset, tmp$
  brOut INSTR <arg>, <]>	; + - after [exx.xx.z+1]
  ife brOut
	brOut=1
  endif
  is INSTR brOut, <arg>, <->		;; MbFor does not (yet) use PPM
  if is gt 1
	tmp$ SUBSTR <arg>, 1, is-1
	ppOffset SUBSTR <arg>, is+1
	if ((opattr tmp$) eq atImmediate) and ((opattr ppOffset) eq atImmediate)
		imm32=tmp$ - ppOffset + PPM31
		push imm32				; two immediates, e.g. MyArray(?)-1
	else
		push tmp$
		ppOffset SUBSTR <arg>, is+1
		ifidn <1>, ppOffset
			dec stack
		else
			sub stack, @SubStr(<arg>, is+1)
		endif
		if PPM31
			add stack, PPM31
		endif
	endif
  else
	is INSTR brOut, <arg>, <+>
	if is gt 1
		tmp$ SUBSTR <arg>, 1, is-1
		ppOffset SUBSTR <arg>, is+1
		if ((opattr tmp$) eq atImmediate) and ((opattr ppOffset) eq atImmediate)
			imm32=tmp$ + ppOffset + PPM31
			push imm32
		else
			push tmp$
			ifidn <1>, ppOffset
				inc stack
			else
				add stack, @SubStr(<arg>, is+1)
			endif
		endif
		if PPM31
			add stack, PPM31
		endif
	elseif PPM31
		if ((opattr arg) eq atImmediate)
			push arg + PPM31
		else
			push arg
			add stack, PPM31
		endif
	elseif type(arg) eq WORD
		tmp$ CATSTR <## line >, %@Line, <: WORD >, <arg>, < not allowed ##>
		% echo tmp$
		.err
	else
		push arg
	endif
  endif
  PPM31 = 0
ENDM

MbFlagTab=-120
MbFlagCsv=-121
shift23 = 23
MbArrayGet$ equ MbArrayGet
Dim MACRO NewMac:REQ, DIM2	; Dim My$() or Dim MyNumber() As DWORD (BYTE, ... REAL10) 
LOCAL isL, isR, MacName$, MaxDim1, MaxDim2, MbDimId, nustr, isC, ReDim, csvtab
  csvtab=0
  ifnb <DIM2>
	isC INSTR <DIM2>, < As >
  else
	isC INSTR <NewMac>, < As >
  endif
  if isC
	StrucDim NewMac, DIM2
	EXITM
  endif
  ifidn <NewMac>, emArr$
		tmp$ CATSTR <## line >, %@Line, <: redimension requires new: keyword ##>
		% echo tmp$
		.err
		EXITM
  endif
  MbDimId = MbArrCt	;; MbArrCt is global, but we need to pass a local var
  ReDim INSTR <NewMac>, <id=>
  if ReDim
	isC INSTR <NewMac>, </>
	isL INSTR <NewMac>, <:>
	MbOldId SUBSTR <NewMac>, 4, isL-4
	if isC
		MaxDim1 SUBSTR <NewMac>, isL+1, isC-isL-1
		MaxDim2 SUBSTR <NewMac>, isC+1
	else
		MaxDim1 SUBSTR <NewMac>, isL+1
	endif
  else
	% isC INSTR <NewMac>, <$>
	ife isC
		.err @CatStr(<## Missing As [TYPE] after Dim >, <NewMac>, < ##>)
	endif
	isL INSTR <NewMac>, <(>
	isC INSTR isL, <NewMac>, <,>
	MacName$ SUBSTR <NewMac>, 1, isL-1
	ifnb <DIM2>
		isR INSTR <DIM2>, <)>
		MaxDim1 SUBSTR <NewMac>, isL+1
		MaxDim2 SUBSTR <DIM2>, 1, isR-1
	else
		isR INSTR <NewMac>, <)>
		MaxDim1 SUBSTR <NewMac>, isL+1, isR-isL-1
	endif
  endif
  ifdif MaxDim1, <-123>
	ifidn MaxDim1, <csv>
			csvtab=1						;; see st2DType
		MaxDim1 equ <0>
		push MbFlagCsv
	elseifidn MaxDim1, <tab>
			csvtab=2
		MaxDim1 equ <0>
		push MbFlagTab
	else
		ifb MaxDim1
			MaxDim1 equ <0>	; no args, Dim My$()
		endif
		% PushPlusMinus MaxDim1
		ifdef MaxDim2
			% PushPlusMinus MaxDim2
			pop eax
			test ah, ah
			ExternDef MbArGetCTH:NEAR
			jne MbArGetCTH
			mov ah, 1		; set negative
			shl eax, shift23
			add [esp], eax
		endif
	endif
	if ReDim
		push MbOldId
	else
		push MbArrCt
	endif
	call MbArrayDim		; inv MAD, ID, ct, name
  endif
  if MbArrCt gt MbMaxArrays
  	tmp$ CATSTR <## n=>, %MbArrCt, <: Too many arrays, increase MbMaxArrays = >, %MbMaxArrays
	% echo tmp$
	.err
  endif
  st2DType=csvtab	; make available after a dim
  ife ReDim
	MacName$ macro arrayElement, dim2		;; string array
	LOCAL is, tmp$
		stSizeG$ equ <DWORD>
		stLastID=MbDimId
		stLastD2 equ <dim2>
		st2DType=csvtab								;; csv 1, tab 2
		ifb <arrayElement>
			tmp$ CATSTR <00>, %MbDimId		;; 00=flag "whole array"
			EXITM tmp$
		elseifidn <arrayElement>, <id>
			EXITM %MbDimId
		elseifidn <arrayElement>, <?>
		if MbUseErrLine
			mov MbErrLine, @Line
		endif
			mov eax, [MbArrTable+4*MbDimId]
			test eax, eax
		ExternDef MbArGetErased:NEAR
		js MbArGetErased
		.if Zero?
			dec eax	; flag not yet defined = -1
		.else
			mov eax, [eax]	; #elements of string array (last el=eax-1)
		.endif
		EXITM <eax>
		else
			is INSTR <arrayElement>, <new:>
			if is
				tmp$ SUBSTR <arrayElement>, 5
				ifb <dim2>
					tmp$ CATSTR <id=>, %MbDimId, <:>, tmp$
				else
					tmp$ CATSTR <id=>, %MbDimId, <:>, tmp$, </>, <dim2>
				endif
				EXITM tmp$
			else
				; OLD: push @Line			; mov MbErrLine, @Line 10 bytes, push only 5
				if MbUseErrLine
					mov MbErrLine, @Line
				endif
				PushPlusMinus arrayElement	;; used also above
				ifnb <dim2>
					% is INSTR <dim2>, <DWord Ptr [esp]>	; aka stack
					if is
						% is INSTR <dim2>, <]>
						if is ne 15
							.err <stack[x] not allowed, use dword ptr [esp+x]>
						endif
						PushPlusMinus dword ptr [esp+4]
					else
						PushPlusMinus dim2
					endif
					pop eax
					mov ah, 1					;; to get identical stack...?
					shl eax, shift23
					add [esp], eax				;; stack needed for redefine!!
				endif
				push MbDimId
				call MbArrayGet$
    				EXITM emArr$
    			endif
    		endif
	ENDM
  	MbArrCt = MbArrCt+1
  endif
ENDM

MbRegList$ equ <eax#ecx#edx#esi#edi#ebx#ebp#esp#>
DefRegPos = 9
; changed from 6 to 10 on 1.3.12 to enable 4 extra MbMacSlot dwords
; changed from 10 to 14 on 17.3.12 to enable 4 extra MbGfSysTime dwords
sDim$ equ <@>
MbArrCtSt = 14	; single erase: get fake pointer from NumArrTable, subtract 6+2=8, MbFree in MbStructErase
StrucDim MACRO NewMac:REQ, DIM2
LOCAL isC, isL, isR, MacName$, Dim1, Dim2, MbDimId, useEL
LOCAL stName, stSize, stCount, tmp$, oa1, oa2, dOnly
	;  tmp$ CATSTR <StrDim >, <NewMac>, <, >, <DIM2>
	;  % echo tmp$
	dOnly INSTR <NewMac>, <-123>		; declare only
	isL INSTR <NewMac>, <##>
	ife isL
		isL INSTR <NewMac>, <[E>
	endif
	if isL
	tmp$ CATSTR <## line >, %@Line, <: Redim not possible ##>
	% echo tmp$
	.err
		EXITM
	endif
	isL INSTR <NewMac>, <(>
	MacName$ SUBSTR <NewMac>, 1, isL-1
	MbDimId	= -MbArrCtSt			;; negative ID: it's a structure or DWORD or ...
	stDimX CATSTR <stDimX>, %(-MbDimId)
	useEL=MbUseErrLine
	ifb <DIM2>
		stDimX = 0					;; we have no Y dimension
		isC INSTR <NewMac>, < As >
		isR INSTR <NewMac>, <)>
		stSize SUBSTR <NewMac>, isC+4
		stCount SUBSTR <NewMac>, isL+1, isR-isL-1
		ifb stCount
			stCount equ <?>
			useEL=1
			ife dOnly
				PushPlusMinus 0
			endif
		elseife dOnly
			PushPlusMinus stCount	; Dim1 only
		endif
	else
		isC INSTR <DIM2>, < As >
		isR INSTR <DIM2>, <)>
		stSize SUBSTR <DIM2>, isC+4
		Dim1 SUBSTR <NewMac>, isL+1
		Dim2 SUBSTR <DIM2>, 1, isR-1
		oa1 = (opattr Dim1) AND 127
		oa2 = (opattr Dim2) AND 127
		if oa2 eq 36
			stDimX = Dim2+1		;; we have X+Y, and X is immediate
		else
			stDimX = -1				;; we have X+Y, but X is a runtime variable
			tmp$ CATSTR <MbDimX>, %(-MbDimId)
			; % echo tmp$
			.DATA?
				tmp$	dd ?			;; global var, rare case
			.CODE
			ife dOnly
				push Dim2					;; e.g. ecx - should not be changed, so we use the stack
				inc stack		;; # of elements = declaration+1
				pop tmp$
			endif
		endif
		if (oa1 eq 36) and (oa2 eq 36)
			stCount=(Dim1+1)*(Dim2+1)-1
			ife dOnly
				push stCount					;; proc will add one more element
			endif
		else
			stCount equ <?>				;; no immediate count
			ife dOnly
				PushPlusMinus Dim2
				inc stack
				ifdifi <eax>, Dim1
					PushPlusMinus Dim1
					pop eax
				endif
				inc eax
				imul eax, [esp]	; (Dim1+1)*(Dim2+1)
				pop edx
				dec eax
				push eax
			endif
		endif
	endif
	isC=0
	% FORC stsc, stSize
		isL INSTR <qdwordsbyte>, <stsc>
		if isL
			isC=isC+1
		endif
	ENDM
	isL SIZESTR stSize
	if (isL le 6) and isC
	tmp$ CATSTR <## line >, %@Line, <: Dim requires UPPERCASE types, e.g. "As BYTE" ##>
	% echo tmp$
	.err
	endif
	ife dOnly
		push stSize							;; struct size
		push MbDimId
		call MbDimStruct			;; inv MAD, ID, size, ct
	endif
	tmp$ CATSTR <stArrType>, %(-MbDimId)	;; for ArraySort
	% tmp$ equ <stSize>
	stReg CATSTR <stReg>, %(-MbDimId)
	stReg = DefRegPos				;; edx; this line says e.g. stReg5 = 9
	@CatStr(<ArChg>, %(-MbDimId), <=0>)
	MacName$ macro xarrE1, arrE2		;; array of structures
	LOCAL oa1, oa2, is, isPM, sc18, isA, tmp$, stCurReg, arrE1, ExMac$, stType, sd2, MustLoadEdx, MbTwo
		ifb <arrE2>
			sDim$ CATSTR sDim$, %@Line, <#>, MacName$, </>, <xarrE1>, <@>	; ->deb
		else
			% is INSTR <arrE2>, <DWord Ptr [esp>
			if is
				.err <stack[x] not allowed, use dword ptr [esp+x]>
			endif
			sDim$ CATSTR sDim$, %@Line, <#>, MacName$, </>, <xarrE1>, <, >, <arrE2>, <@>
		endif
		isA SIZESTR sDim$
		if isA gt 200
			is INSTR 20, sDim$, <@>
			if is
				sDim$ SUBSTR sDim$, is
			endif 
		endif
		stLastID = MbDimId						;; Let MyStruct(1)=MyStruct(eax)
		stLastIDs = MbDimId					;; for MovVal
		stLastEl equ <xarrE1>
		sLine=@Line								;; for Val
		stSizeG$ equ <stSize>
		stSizeG = stSize
		stCtG=0
		if @CatStr(<ArChg>, %(-MbDimId))
			stCount equ <?>					; declare array dynamic
		endif
		if (opattr stCount) ne atImmediate
			ifidn stCount, <?>
				stCtG=1
				immAdd$ equ <>
				stLastArg equ <xarrE1>
			endif
		endif
		stLastType = ChkNum(stSize ptr [edx])
		MbArrXY=0
		sd2 SIZESTR <arrE2>
		arrE1 equ <xarrE1>						;; default: element 1 as received
		ifb arrE1
			EXITM @CatStr(<-0>, %(-MbDimId))		;; -0=flag "whole array", id is negative
		elseifidn arrE1, <XY>
			MbArrXY=256
			EXITM @CatStr(<-0>, %(-MbDimId))		;; -0=..
		elseifidn arrE1, <id>
			EXITM %MbDimId
		elseifidn arrE1, <+>			;; for ArraySort: ()=-09, (+) or (-)=-09:edx, (+:123)=-09:+123, (-:eax)=-09:-eax
			mov eax, [NumArrTable+4*MbDimId]
			mov edx, [eax-8]		; #elements of struct (last el=eax-1)
			EXITM @CatStr(<-0>, %(-MbDimId), <:edx>)		; full array, ascending
		elseifidn arrE1, <->			;; full array, descending
			mov eax, [NumArrTable+4*MbDimId]
			mov edx, [eax-8]			; #elements (last el=eax-1)
			EXITM @CatStr(<-0>, %(-MbDimId), <:-edx>)		; full array, descending
		elseifidn arrE1, <?>			; #elements (last el=eax-1)
			if (opattr stCount) eq atImmediate
				EXITM %(stCount+1)
			else
				mov eax, [NumArrTable+4*MbDimId]
				mov eax, [eax-8]
				EXITM <eax>
			endif
		else
			if @InStr(1, arrE1, <new:>)
				.err <## Redim not possible, but autoexpand works ##>
				exitm <>
			endif
			stReg CATSTR <stReg>, %(-MbDimId)
			isA INSTR arrE1, <:>	; e.g. MyStruc(esi:123, eax): load & assume reg32, then leave
			if isA						; assign reg32
				arrE1		SUBSTR <xarrE1>, isA+1	;; element 1 is rest after exx:
				stCurReg	SUBSTR <xarrE1>, 1, isA-1	;; assume reg32, e.g. esi
				ifidn stCurReg, <+>
					EXITM @CatStr(<-0>, %(-MbDimId), <:+>, arrE1)	;; for ArraySort
				endif
				ifidn stCurReg, <->
					EXITM @CatStr(<-0>, %(-MbDimId), <:->, arrE1)	;; descending
				endif
				is INSTR MbRegList$, stCurReg
				stReg = is								;; JWasm chokes for str instr...
			elseifidn arrE1, <none>	;; new syntax: md(none)
				stReg = DefRegPos	;; flag use edx, otherwise do nothing
				EXITM <>
			endif
;			mov eax, [Exx.RECT.left+offset]
			stCurReg SUBSTR MbRegList$, stReg+1, 2
			stCurReg CATSTR <E>, stCurReg		;; e.g. Esi
			MustLoadEdx = 1 and (stReg eq DefRegPos)		;; 0=assume set or loading
			stDimX CATSTR <stDimX>, %(-MbDimId)
			MbTwo = (isA or MustLoadEdx) and (stDimX ne 0)	;; two args expected?
			stType INSTR stSize, <WORD>		;; dword, qword, oword etc
			ife stType
			  stType INSTR stSize, <BYTE>		;; allow TBYTE ? not a scaling factor (1/2/4/8)...
			  ife stType
				stType INSTR stSize, <REAL>		;; allow REAL10? not a scaling factor...
			  endif
			endif
			isPM=0
			is INSTR arrE1, <]>
			ife is
				isPM INSTR arrE1, <+>		; xy(ecx+1)
				ife isPM
					isPM INSTR arrE1, <->
				endif
				if isPM
					immAdd$ SUBSTR arrE1, isPM
					arrE1 SUBSTR arrE1, 1, isPM-1
				endif
			endif
			if stType							; ready to add offset
				ExMac$ CATSTR stSize, < ptr [>, stCurReg
				; syntax examples:
				; mov xmm0, OWORD ptr [Exx+offset]
				; fild TBYTE ptr [Exx+offset]
				; fld REAL8 ptr [Exx+offset]
				; mov eax, DWORD ptr [Exx+offset]
			elseif MustLoadEdx and (sd2 eq 0)			;; structure and arg1 only: copy strucs withLet
				if useEL
					mov stCurReg, [NumArrTable+4*MbDimId]
					mov eax, [stCurReg-8]
					.if eax<=sdword ptr arrE1
						push MbDimId
						call MbSAP		; requested el# in eax - see MbArrExpand for strings
					.endif
				endif
				; immAdd$
				EXITM @CatStr(<[EL:>, arrE1, <]>)  	; flag [E for Let plus L: to indicate full copy
			else			 							; dot: structure field
				if sd2
				  ExMac$ CATSTR <[>, stCurReg, <.>, stSize, <.&arrE2>		; e.g. [edx.RECT.left+eax]
				else
				  ExMac$ CATSTR <[>, stCurReg, <.>, stSize, <.>, arrE1		; e.g. [esi.RECT.left+eax]
				endif
			endif
			if isPM
				ExMac$ CATSTR ExMac$, immAdd$, <*>, stSize
			endif
			is = stReg
			stElementSize = 0		;; unknown
			if sd2 or stType			;; syntax MyStruc(element, member) overrides assume
				is = DefRegPos
				if stType
					stElementSize = stType			; mydw(3,5)->3*cols+5
				else
					tmp$ CATSTR stSize, <.&arrE2>	; myrect(1,right)
					stElementSize = sizeof tmp$
				endif
			endif
			if MustLoadEdx or isA				;; it's edx or a new assign
				mov stCurReg, [NumArrTable+4*MbDimId]
				if useEL
					if MbUseErrLine
						mov MbErrLine, @Line		; debug version uses error line...
					endif
					push eax
					ifidni <eax>, arrE1		; ... and checks boundaries (1/2013)
						.if sdword ptr arrE1>[stCurReg-8]
					else
						mov eax, [stCurReg-8]
						if isPM
							sub eax, immAdd$
						endif
						.if eax<=sdword ptr arrE1	; 2nd arg can be imm
					endif
						; equal, so eax=arrE1
						push MbDimId
						if isPM
							ifidn immAdd$, <+1>
								inc eax
							else
								add eax, immAdd$	; correct the eax passed to mbsap
							endif
						endif
						call MbSAP		; requested el# in eax
						mov edx, [NumArrTable+4*MbDimId]
					.endif
					pop eax
				endif
			endif
			; -------- stCurReg points to arraystart or assigned element --------
			if stType		; ##### md(3,eax) or md(eax, 3) or md(3,3) or md(3) or md(eax) ---------------------------------------------------------------------------------------
				sc18 = (stSize eq 1) or (stSize eq 2) or (stSize eq 4) or (stSize eq 8)	; scaling possible
				oa1 = opattr arrE1				; there is no structure.field, ok for JWasm
				if (sd2 ne 0) xor (MbTwo ne 0)
					tmp$ CATSTR <## line >, %@Line, <: wrong # of args, expected: >, %(1-(MbTwo gt 0)), < ##>
					% echo tmp$
					.err
					exitm <eax>		;; avoids obscure error messages
				endif
				if sd2		; two args
					oa2 = opattr arrE2		; md(esi:eax, ecx) or md(esi:77) or md(esi:n, eax)??
					if stDimX gt 0		; immediate dimcount
						if (oa1 eq atImmediate) and (oa2 eq atImmediate)
							ExMac$ CATSTR ExMac$, <+>, %(arrE1*stSize*stDimX+arrE2*stSize)	; md(3,7): [edx+3*dxi*sz+7*sz]
						elseif oa1 eq atImmediate			; md(3, gv)
							if (oa2 eq atRegister) and sc18
								ExMac$ CATSTR ExMac$, <+>, %(arrE1*stSize*stDimX), <+>, <arrE2*stSize>
							else
								push eax
								imul eax, arrE2, stSize		; test with DoMov=0 and TBYTE or OWORD
								lea stCurReg, [stCurReg+arrE1*stSize*stDimX+eax]
								pop eax
							endif
						elseif oa2 eq atImmediate			; md(gv, 3)
							push eax
							imul eax, arrE1, stSize*stDimX
							add stCurReg, eax
							ExMac$ CATSTR ExMac$, <+>,  %arrE2*stSize	; eax will be popped before exmac
							pop eax
						else								; md(gv, eax) or md(eax, gv)
							push eax
							push arrE2
							imul eax, arrE1, stSize*stDimX
							add stCurReg, eax
							imul eax, [esp], stSize			;; arrE2*stSize
							add stCurReg, eax
							pop eax
							pop eax	; ->add44
						endif
					else					; dimcount in global variable 
						dxgv CATSTR <MbDimX>, %(-MbDimId)
						if oa2 eq atImmediate
							push eax
							if oa1 eq atImmediate
								imul eax, dxgv, arrE1*stSize
							else
								imul eax, dxgv, stSize
								imul eax, arrE1
							endif
						; md(99, x): eax=99*dimx*size, now add x*size
							add stCurReg, eax
							pop eax
							ExMac$ CATSTR ExMac$, <+>,  %arrE2*stSize	; eax will be popped before exmac
						else
							push eax		; save eax
							push arrE2
							if oa1 eq atImmediate
								imul eax, dxgv, arrE1*stSize		; add44
							else
								imul eax, dxgv, stSize
								imul eax, arrE1
							endif
							add stCurReg, eax			; E1*20 added
							pop eax				; arrE2
							imul eax, eax, stSize		; gv or eax: 4
							add stCurReg, eax
							pop eax				; restore eax
						endif
					endif
				elseife MustLoadEdx
					if oa1 eq atImmediate
						ExMac$ CATSTR ExMac$, <+>,  %arrE1*stSize
					elseif (oa1 eq atRegister) and sc18
						ExMac$ CATSTR ExMac$, <+>,  arrE1, <*stSize>
					else
						imul edx, arrE1, stSize		; shortest for reg32 and gloval vars
						ExMac$ CATSTR ExMac$, <+edx>
					endif
				else
					if oa1 eq atImmediate
						ExMac$ CATSTR ExMac$, <+>,  %arrE1*stSize
					elseif (oa1 eq atRegister) and sc18
						ExMac$ CATSTR ExMac$, <+>,  arrE1, <*stSize>
					else
						push stCurReg
						if stSize eq 1
							mov stCurReg, arrE1			; byte array
						else
							imul stCurReg, arrE1, stSize	; arrE1 is a memory variable
						endif
						add stCurReg, [esp]
						add esp, 4					; no pop, no reg trashed, ExMac$ is OK
					endif
				endif
				if isA		; new assign: point reg32 to current element, e.g. md(esi:77, ecx)
					lea stCurReg, @CatStr(ExMac$, <]>)
					EXITM <>
				endif
				; ExMac$ CATSTR stSize, < ptr >, ExMac$ see ^, stType (8/13)
			else			; mr(3, left) or mr(eax, right) or mr(n, bottom) or mr(left) ----------------------------------------------------------------------------------------------------
				oa1 INSTR arrE1, <.>
				ife oa1
					oa1 = opattr arrE1		; JWasm doesn't like structure.field
				endif
				if isA		; new assign: point reg32 to current element, e.g. mr(esi:77)
					if oa1 eq atImmediate			;; element passed as immediate
						lea stCurReg, [stCurReg+stSize*arrE1]
					elseif (oa1 eq atRegister) and ((stSize eq 1) or (stSize eq 2) or (stSize eq 4) or (stSize eq 8))
						lea stCurReg, [stCurReg+stSize*arrE1]
					else
						push eax
						imul eax, arrE1, stSize		; eax, src, imm8 - src can be memory
						add stCurReg, eax
						pop eax
					endif
					EXITM <>
				elseif MustLoadEdx				;; arrE1 is element, arrE2 is field
					if oa1 eq atImmediate			;; element passed as immediate
						ExMac$ CATSTR ExMac$, <+>, %arrE1*stSize
					elseif (oa1 eq atRegister) and ((stSize eq 1) or (stSize eq 2) or (stSize eq 4) or (stSize eq 8))
						ExMac$ CATSTR ExMac$, <+>, arrE1, <*stSize>
					else
						push eax
						ifdifi <eax>, arrE1
							mov eax, arrE1
						endif
						imul eax, eax, stSize
						add stCurReg, eax
						pop eax
					endif
				endif
	   		endif
	   		EXITM @CatStr(ExMac$, <]>)
    		endif
	ENDM	; ------------------------------------------ end MacName$ -----------------------------------------
	MbArrCtSt	= MbArrCtSt+1
	if MbArrCtSt gt MbMaxArrays+10
	  	tmp$ CATSTR <## n=>, %MbArrCtSt, <: Too many arrays, increase MbMaxArrays = >, %MbMaxArrays
		% echo tmp$
		.err
	endif
ENDM

VarPtr MACRO arrEl:REQ	; mov eax, VarPtr(rc(0)) or mov eax, VarPtr(rc(3, top))
LOCAL isL, isR, el$, tmp$	; for string arrays simply use mov eax, My$(123)
  % tmp$ CATSTR <arrEl>, < >	; JWasm needs %
  isL INSTR tmp$, <[EL:>
  isR INSTR tmp$, <]>
  ife isR
	.err @CatStr(<## Struct array expected in line >, %@Line, < ##>)
	EXITM <eax>
  elseif isL
	el$ SUBSTR tmp$, isL+4, isR-isL-4
	isR INSTR el$, <[>
	if isR
		el$ CATSTR el$, <]>
		imul edx, el$, stSizeG
	elseif (opattr el$) eq atImmediate
		mov edx, el$*stSizeG
	else
		imul edx, el$, stSizeG
	endif
	add edx, [NumArrTable+4*stLastID]	; add offset element 0
	EXITM <edx>
  else
	% isL INSTR <arrEl>, <[Edx+0]>	; vp(0)
	ife isL
		lea edx, arrEl	; [Edx.RECT.right+0]
	endif
	EXITM <edx>
  endif
ENDM
; must follow Dim macro (no code produced, they just define array IDs - do NOT fumble here):
Dim Files$(-123)		; does not produce code but will be run once even if never called
Dim Files2$(-123)		; for swapping with OWORD array FileTime+Size, see ebX==1 || ebX==2
Dim Dlg$(-123)			; for dialog return values
Dim Maps(-123) As apMAP	; for ArrayPlot
Dim LgTb$(-123)			; for Lg$

wFiles$ MACRO arg
  mov edx, MbArrTable[4]
  if (opattr arg) eq atImmediate or (opattr arg) eq atRegister
	push [edx+8*arg+StringArrHeader]	; src
  else
	m2m eax, arg
	push [edx+8*eax+StringArrHeader]
  endif
  call MbBufferGet			; dest
  push eax
  call wDataP		; returns end of buffer in edx
  push 1
  push edx
  call MbBufferFix
  EXITM <( eAx)>
ENDM

apMAP STRUCT
numPoly	dd ?	; #main regions
pNames	dd ?	; ptr to names array
pPalette	dd ?	; ptr to palette
polyWH	dd ?	; pFcp-4:	if (plot width or 65536*plot height)<>polyWH then create new polygons
pFcp	dd ?	; pXY-4:	ptr to array of flags, colours, polygon handles
pXY	dd ?	; ptr to array of REAL4 coordinates
flagPiR	dd ?	; flag point in region
pPos	dd ?	; ptr to byte array read from *.pos file
cbProc	dd ?	; ptr to callback proc
res1	dd ?	; reserved
apMAP ENDS
Swap MACRO arrId1, arrId2
LOCAL isA, isB, tmp$
  isA INSTR <arrId1>, <#>
  isB INSTR <arrId2>, <#>
  if isA*isB
	isA INSTR <arrId1>, <$(>
	isB INSTR <arrId2>, <$(>
	if isA ne isB
		.err <invalid args>
	endif
	tmp$ CATSTR  @SubStr(<arrId1>, 2, isA-1), <(id)>
	push ecx
	push @SubStr(<arrId1>, isA+1)	; push x$(whatever)
	push @SubStr(<arrId2>, isB+1)
	mov eax, [MbArrTable+4*tmp$]
	pop edx
	pop ecx
	push [eax+8*edx+StringArrHeader]
	push [eax+8*edx+StringArrHeader+4]
	push [eax+8*ecx+StringArrHeader]
	push [eax+8*ecx+StringArrHeader+4]
	pop [eax+8*edx+StringArrHeader+4]
	pop [eax+8*edx+StringArrHeader]
	pop [eax+8*ecx+StringArrHeader+4]
	pop [eax+8*ecx+StringArrHeader]
	pop ecx
	EXITM
  endif
  if ((opattr arrId1)+(opattr arrId2) and 127) eq 72	; two immediates = two arrays
	push arrId1
	push arrId2
	call MbArraySwap
  else
	isA INSTR <arrId1>, emArr$
	isB INSTR <arrId2>, emArr$
	if isA or isB
		.err @CatStr(<## line >, %@Line, < not allowed: use Swap #x$(a), #x$(b) with JWasm ##>)
	endif
	if type(arrId1) gt DWORD
		ffree st(7)
		fld arrId1
		ffree st(7)
		fld arrId2
		fstp arrId1
		fstp arrId2
	else
		xchg eax, arrId1	; string and int swap
		xchg eax, arrId2
		xchg eax, arrId1
	endif
  endif
ENDM

ArrayRead MACRO arrID, fname
  MbAR PROTO
  @CatStr(<ArChg>, %(-arrID), <=1>)
  push repargA(fname)
  push arrID
  call MbAR
ENDM

ArrayStore equ <Store>
ArrPlot STRUCT
  apRectL	RECT <>
  apRectG	RECT <>
  apSize	SIZEL <>		; Masm32: x, y
  apDC	dd ?
  apMemDC	dd ?
  apBitmap	dd ?
  apBitmap2	dd ?
  apOldBmp	dd ?
  apCtrl	dd ?
  apFontBig	dd ?
  apXmin	REAL4 ?
  apXrange	REAL4 ?
  apYmin	REAL4 ?
  apYrange	REAL4 ?
  apBarX	db ?
  apBarGap	db ?
  apResB1	db ?
  apResB2	db ?
  apResD1	dd ?
  apGdisi	GdiplusStartupInput <>
  apGdiToken	dd ?
  apGdiDC	dd ?
  apGdiPath	dd ?
;   apBmCurW	dd ?
;   apBmCurH	dd ?
  apPs	PAINTSTRUCT <>
ArrPlot ENDS
EXTERNDEF	apStruct:ArrPlot
ArrayLoadMap MACRO MapIndex, fname
  stLastType=MbReal4
  invoke MbDBM, MapIndex, repargA(fname)
ENDM

ArrayMapRegion MACRO lParam:=<lParam>, TestMap:=<0>, hCtrl:=<0>
  MbDbGetRgn PROTO: DWORD, :DWORD, :DWORD
  push hCtrl
  push TestMap
  push lParam
  call MbDbGetRgn
  ifidn <hCtrl>, <0>
	EXITM <eax>
  else
	EXITM <>
  endif
ENDM

apStacked=64		; default: not stacked
apBars=4096
apBarGap=0		; see apBarX
; apXY=256		; ah:1
; apUseLines=512		; ah:2
; apSetRange=1024	; ah:4
; apUseRange=2048	; ah:8
; APs equ [edi.ArrPlot]
; ArrayPlot Freq(), hCtrl, Width%, Height%, dotcol, dotSize, xMin, xMax
ArrayPlot MACRO arrID, dotcol:=<0>, dotSize1:=<1>, apMargins:=<-1>, xMin:=<0>, xMax:=<-1>, stacked:=<0>
LOCAL is, sr$, fnt$, xyFlag, lineSize, barSize, barGap, dotsize, arrTypeAndFlags, isGui
  isGui=0
  ifdef PtDC
	ifidn PtDC, <esi>
		isGui=1
	endif
  endif
  barSize INSTR <dotSize1>, <bars>
  lineSize INSTR <dotSize1>, <lines>
  if lineSize
	dotSize SUBSTR <dotSize1>, lineSize+6
	lineSize=512
  elseif barSize
	dotSize SUBSTR <dotSize1>, barSize+5
	barSize=apBars
  else
	dotSize equ <dotSize1>
  endif
  ifidni <arrID>, <ClrRange>
	Clr APs.apYrange
  elseifidni <arrID>, <exit>
	if apIn ne 1
		.err @CatStr(<## line >, %@Line, <: ArrayPlot not initialised ##>)
	endif
	invoke GetClientRect, APs.apCtrl, addr APs.apRectG
	ifdif  <dotcol>, <0>
		ifidn <dotcol>, emArr$
			mov esi, Cat$(dotcol)
		else
			mov esi, repargA(dotcol)
		endif
		invoke SetBkMode, APs.apMemDC, TRANSPARENT
		.if !APs.apFontBig
			is INSTR <dotSize>, <">
			if is
				MakeFont APs.apFontBig, Height:36, dotSize, Weight:600
			else
				MakeFont APs.apFontBig, Height:36, "Times New Roman", Weight:600
			endif
		.endif
		push rv(SelectObject, APs.apMemDC, APs.apFontBig)
		push APs.apMemDC
		push Len(esi)
		lea edx, APs.apSize
		invoke GetTextExtentPoint32, APs.apMemDC, esi, eax, edx
		mov edx, APs.apRectG.right	; center using last plot's margins
		add edx, APs.apRectG.left
		sub edx, APs.apSize.x
		sar edx, 1
		pop eax
		invoke TextOut, APs.apMemDC, edx, 3, esi, eax
		call SelectObject
	endif
	ife isGui	; Gui apps do this part in the WM_PAINT handler
		invoke BitBlt, APs.apDC, 0, 0, APs.apRectG.right, APs.apRectG.bottom, APs.apMemDC, 0, 0, SRCCOPY
		invoke SelectObject, APs.apMemDC, APs.apOldBmp
		invoke EndPaint, APs.apCtrl, addr APs.apPs
	endif
	pop ebx
	pop edi
	pop esi
  elseif (opattr arrID) eq atImmediate
	xyFlag=MbArrXY
	if arrID ge 0
		xyFlag=256
		stLastType=MbReal4	; force map format
	endif
	if stLastType eq MbReal10
		.err <## REAL10 arrays not allowed in ArrayPlot, sorry ##>
	endif
	arrTypeAndFlags=stLastType or stacked*apStacked or xyFlag or lineSize or barSize
	if stacked
		arrTypeAndFlags=arrTypeAndFlags or apStacked
	endif
	sr$ equ <xMin>
	ifidni sr$, <setrange>
		sr$ equ <0>
		arrTypeAndFlags=arrTypeAndFlags or 1024	; apSetRange
	endif
	if barSize
		ife apBarX
			if apBarGap lt 2
				mov APs.apBarX, 5	; minimum is 5px
			else
				mov APs.apBarX, apBarGap+2
			endif
			mov APs.apBarGap, apBarGap
			apBarX=1
		endif
	endif
	invoke MbArrayPlot, arrID, arrTypeAndFlags, apMargins, dotcol, dotSize, sr$, xMax
	if barSize
		add APs.apBarX, apBarGap+dotSize	; must be immediate
	endif
  elseif (opattr arrID) eq atRegister
	ife lineSize
		lineSize=512	; map must have lines
		dotSize equ <2>
	endif
	arrTypeAndFlags=MbReal4 or stacked*apStacked or 256 or lineSize
	if stacked
		arrTypeAndFlags=arrTypeAndFlags or apStacked
	endif
	invoke MbArrayPlot, arrID, arrTypeAndFlags, apMargins, dotcol, dotSize, xMin, xMax
  else
	apIn=1
	apBarX=0
	push esi	; AP Init
	push edi
	push ebx
	mov edi, offset apStruct
	mov eax, arrID	; arrID = e.g. hEdit
	mov APs.apCtrl, eax
	ife isGui
		lea edx, APs.apPs
		invoke BeginPaint, eax, edx
		mov APs.apDC, eax	; rv(GetDC, APs.apCtrl)
		mov eax, APs.apBitmap
		.if !eax			; create once compatible DC and bitmap
			invoke SystemParametersInfo, SPI_GETWORKAREA, 0, addr APs.apRectG, 0		; edi=addr RECT
			mov APs.apMemDC, rv(CreateCompatibleDC, APs.apDC)
			mov APs.apBitmap, rv(CreateCompatibleBitmap, APs.apDC, APs.apRectG.right, APs.apRectG.bottom)	; hDC, not memDC!
		.endif
		mov APs.apOldBmp, rv(SelectObject, APs.apMemDC, eax)
	endif
	ifdif  <dotcol>, <0>
		invoke GetClientRect, APs.apCtrl, edi
		mov eax, dotcol	; bgColor
		dec eax
		and eax, 0ffffffh
		push rv(CreateSolidBrush, eax)
		invoke FillRect, APs.apMemDC, edi, eax
		call DeleteObject	; brush
	endif
  endif
ENDM	; ArrayPlot end

ArraySet MACRO arrID, args0:VARARG	; ArraySet MyR4() = 1.0, 2.0, 3.0e4
LOCAL is, oa, asData, args, asType, txAs$, numID, tmp$
  is INSTR <arrID>, <=>
  numID SUBSTR <arrID>, 1, is-1
  oa = opattr numID
  if oa ne atImmediate
	oa=0
  else
	oa=numID
  endif
  args CATSTR @SubStr(<arrID>, is+1), <, >, <args0>
  if @InStr(1, <arrID>, <$>) or oa GT 0
	.DATA
	txAs$ LABEL BYTE
	db @SubStr(<arrID>, is+1), 13, 10
	for arg, <args0>
		db arg, 13, 10
	endm
	db 0
	.CODE
	% StringToArray offset txAs$, numID
	EXITM
  endif
  ife oa
	tmp$ CATSTR <## line >, %@Line, <: numeric array >, numID, <needs to be fixed size and Dim'ed before ##>
	% echo tmp$
	.err
	EXITM
  endif
  .DATA
  if stLastType eq MbDword
	asType equ <dd>
  elseif stLastType eq MbReal4
	asType equ <REAL4>
  elseif stLastType eq MbReal8
	asType equ <REAL8>
  else
	.err <invalid type>
  endif
  asData asType args
  .CODE
  pushad
  mov esi, offset asData
  mov edi, [NumArrTable+4*@SubStr(<arrID>, 1, is-1)]
  if stLastType eq MbDword
	m2m ecx, LENGTHOF asData
	rep movsd
  else
	m2m ecx, (LENGTHOF asData)-1
	ffree st(7)
	.Repeat
		fld asType PTR [esi+asType*ecx]
		fstp asType PTR [edi+asType*ecx]
		dec ecx
	.Until Sign?
  endif
  popad
ENDM

wArrayFill MACRO ArrID:REQ, args:=<0>
  MbWideLet=1024
  ArrayFill ArrID, args
ENDM
ArrayFill MACRO ArrID:REQ, args:=<0>
LOCAL tmp$, isUC
  oa = (opattr args) AND 127
;	tmp$ CATSTR <MyArray=>, <ArrID>, < with [>, <args>, <], lastID=>, %stLastID, < and opa=>, %oa
;	% echo tmp$
;	atRegister:	al, ax, eax with stosb...d
;	atGlobal:	<dword: stosb...d
;	offset + x for anything > dword AND size match, rep movsb...d
;	atImmediate:	x, rep movsb...d
  if stLastID gt 0
;	echo ## strings
	push ebx
	isUC=MbWideLet	; MbWideLet gets reset by Let below, therefore a local isUC
	ifdif <args>, <0>
		push esi
		Let esi=args	; = wLet if MbWideLet is set
	endif
	mov eax, [MbArrTable+4*stLastID]
	mov ebx, [eax.StringArrHeader.numEL]		; #string elements (last el=eax-1)
	.While 1
		dec ebx
		.Break .if Sign?
		push ebx
		push stLastID
		call MbArrayGet
		ifdif <args>, <0>
			push esi
			push 80000001h+isUC
			call MbPrint	; Let My$(ebx)=esi
		else
			push 0
			call MbInsert	; Clr L$(123): clear an array element (assigns an empty string)
		endif
	.Endw
	ifdif <args>, <0>
		Clr$ esi	;; absolutely needed!
		pop esi
	endif
	pop ebx
  else
;	echo ## strucs
	push edi
	push ecx
	mov edi, [NumArrTable+4*stLastID]
	if (oa eq atOffset) or (oa eq atGlobal)
		push esi
		mov edx, [edi-8]	; #numeric elements
		push stSizeG
		.Repeat
			if oa eq atGlobal
				if sizeof args ne stSizeG
				    .err <size no good>
				endif
				mov esi, offset args	; reload source
			else
				mov esi, args
			endif
			mov ecx, [esp]	; get counter per element
			rep movsb
			dec edx
		.Until Zero?
		pop eax	; adjust the stack
		pop esi		; restore esi
	elseif oa eq atRegister
		if @SizeStr(<args>) le 2	; word or byte register
			ifidni <x>, @SubStr(<args>, 2, 1)
				ifdifi <args>, <ax>
					mov ax, args
				endif
				mov ecx, [edi-8]	; #elements
				imul ecx, stSizeG/2
				rep stosw
			else
				ifdifi <args>, <al>
					mov al, args
				endif
				mov ecx, [edi-8]	; #elements
				rep stosb
			endif
		elseif stSizeG mod 4	; not by DWORD
			.err <invalid size>
		else
			ifdifi <args>, <eax>
				mov eax, args
			endif
			mov ecx, [edi-8]	; #elements
			shr ecx, 2
			rep stosd
		endif
	elseif oa eq atImmediate
		mov ecx, [edi-8]	; #elements
		if stSizeG eq 4
			mov eax, args
			rep stosd
		elseif stSizeG eq 2
			mov ax, args
			rep stosw
		else
			mov al, args
			rep stosb
			if stSizeG gt 1
				% echo ## Warning: &args& interpreted as byte in line @Line
			endif
		endif
	endif
	pop ecx
	pop edi
  endif
ENDM

fldAny macro arg, fsize:=<REAL4>
LOCAL oa, is, tmpF
  % is INSTR <arg>, <.>
  if is
	.DATA
	tmpF fsize arg
	.CODE
	fld tmpF
  else
	oa = (opattr arg) AND 127
	if oa eq atImmediate or oa eq atRegister
		push arg
		fild stack
		if oa eq atImmediate
			add esp, 4
		else
			pop arg
		endif
	elseif type(arg) eq REAL4 or type(arg) eq REAL8 or type(arg) eq REAL10
		fld arg
	else
		fild arg 
	endif
  endif
ENDM

SetFloat MACRO destsrc
Local is, dest, src
  is INSTR <destsrc>, <=>
  dest SUBSTR <destsrc>, 1, is-1
  src SUBSTR <destsrc>, is+1
  ifdif src, <ST(0)>
	.err <## SetFloat expects a function returning ST(0) ##>
  endif
  fstp dest
ENDM
SetInt MACRO arg
  if (opattr arg) eq atRegister
	push arg
	fistp stack
	pop arg
  else
	fistp arg
  endif
ENDM
Float MACRO arg
  push arg
  fild dword ptr [esp]
  add esp, 4
  EXITM <ST(0)>
ENDM
Mb180ByPi equ MbPiBy180[10]
Cosinus MACRO arg, fs2:=<0>
  FpuPush arg
  ifidni <fs2>, <rad>
	fld Mb180ByPi
	fmul
	push 90
	fild stack
	fsubr
	add esp, 4
	call MbSinP
  elseif fs2
	fld MbPiBy180
	fmul
	fcos
  else
	push 90
	fild stack
	fsubr
	add esp, 4
	call MbSinP
  endif
  EXITM <ST(0)>
ENDM  
Sinus MACRO arg, fs2:=<0>
  FpuPush arg
  ifidni <fs2>, <rad>
	fld Mb180ByPi
	fmul
	call MbSinP
  elseif fs2
	fld MbPiBy180
	fmul
	fsin
  else
	call MbSinP
  endif
  EXITM <ST(0)>
ENDM
MbPOLY STRUCT
a0	REAL10 ?
a1	REAL10 ?
a2	REAL10 ?
dummy	dw ?
MbPOLY ENDS
SetPoly3 MACRO src0
LOCAL is, p3type, src, p3, t4$, p3size, p3sPtr, inx, tmp$, fld$
  ffree st(2)
  ffree st(3)
  ffree st(4)
  ffree st(5)
  ffree st(6)
  ffree st(7)
  is INSTR <src0>, <:>
  src SUBSTR <src0>, is+1
  if is eq 2
	inx SUBSTR <src0>, 1, 1
  else
	inx equ <0>
  endif
  is INSTR src, <-0>	; numerical array?
  if is
	; % echo ARRAY: tmp$
	p3type = stLastType
	if p3type eq MbReal8
		p3size equ <REAL8>
	elseif p3type eq MbReal4
		p3size equ REAL4
	else
		p3size equ DWORD
	endif
	mov eax, NumArrTable[4*src]	; ID passed
  else
	; % echo non-array: tmp$
	p3type = MbReal8	; default is double
	is INSTR src, <:>
	if is
		t4$ SUBSTR src, 1, 4
		p3size SUBSTR src, 1, is-1
		src SUBSTR src, is+1
		ifidni t4$, <real>
			if type(src) eq REAL4
				p3type = MbReal4
			endif
		else
			p3type = MbDword
		endif
	else
		if type(src) eq DWORD
			p3size equ <DWORD>
		elseif type(src) eq REAL4
			p3size equ <REAL4>
		elseif type(src) eq REAL8
			p3size equ <REAL8>
		elseif type(src) eq REAL10
			p3size equ <REAL10>
		else
			.err <bad type>
		endif
		if (opattr src) ne atRegister
			p3type = ChkNum(src)
		endif
	endif
	ifdifi src, <eax>
		if (opattr src) eq atRegister
			mov eax, src
		elseif (opattr src) eq atMemory
			lea eax, src
		else
			mov eax, offset src
		endif
	endif
  endif
  @CatStr(<p3t>, %inx, < = >, p3type)	; define MbType for GetPoly3
  p3 equ <[edx.MbPOLY]>
  ExternDef MbPoly3:MbPOLY
  mov edx, offset MbPoly3[MbPOLY*inx]	; inx 0...9
  if p3type eq MbDword
	fld$ equ <fild>
  else
	fld$ equ <fld>
  endif
  p3 equ <[edx.MbPOLY]>
  tmp$ CATSTR <p3sPtr equ REAL>, %p3size, < PTR>
  tmp$
  fld$ p3sPtr [eax+p3size]	; y0
  fld st			; keep a copy of y0
  fld st			; copy for pop
  fstp p3.a0		; a0 = y0
  fld$ p3sPtr [eax+3*p3size]	; A(1)=(y(1)-y(0)) / (x(1)-x(0)), y(1)-y(0)
  fsubr
  fld$ p3sPtr [eax+2*p3size]	; x1
  fld$ p3sPtr [eax+0*p3size]	; x(1)-x(0)
  fsub
  fdiv
  fstp p3.a1
  fld$ p3sPtr [eax+5*p3size]	; y2-y0
  fsubr
  fld$ p3sPtr [eax+4*p3size]	; x2
  fld$ p3sPtr [eax+0*p3size]	; x(2)-x(0)
  fsub
  fdiv			; A(2)=(y(2)-y(0)) / (x(2)-x(0)) = (2-2.5)/(3.5-1.5) = -0.25
  fld p3.a1
  fsub		; A(2)=(A(2)-A(1)) / (x(2)-x&(1)) = -0.25- (-1.5) = 1.25
  fld$ p3sPtr [eax+4*p3size]
  fld$ p3sPtr [eax+2*p3size]	; A(2)=(A(2)-A(1)) / (x(2)-x&(1))
  fsub
  fdiv			; A(2)=a/b
  fld st			; copy for pop
  fstp p3.a2		; a2
  fld$ p3sPtr [eax+0*p3size]	; x0
  fld st			; x0
  fld$ p3sPtr [eax+2*p3size]	; x0*x1
  fmul
  fmulp st(2), st	; A2*x0*x1
  fld p3.a1
  fmul
  fsub
  fld p3.a0
  fadd
  fstp p3.a0
  fld$ p3sPtr [eax+0*p3size]	; x0
  fld$ p3sPtr [eax+2*p3size]	; x1
  fadd
  fld p3.a2
  fmul
  fld p3.a1
  fsub
  fchs
  fstp p3.a1
ENDM
gp3 macro p3Type	; x is on FPU
  fld st			; copy of x
  fld [edx.MbPOLY].a2
  fmul
  fmul st, st(1)  	; X*X*a2
  fxch
  fld [edx.MbPOLY].a1	; X*a1
  fmul
  faddp st(1), st
  fld [edx.MbPOLY].a0	; a0+a1*X+a2*X2
  fadd
ENDM

; GetPoly MyArr() = take all x vals, fill y vals
; GetPoly MyArr(), 9 = take 9 x vals, fill y vals
; GetPoly 3:MyArr(), 9, 1.5, 0.5 = use slot 3, fill 9 elements starting with 1.5 and adding 0.5
; GetPoly any = take one x val, return y on FPU
GetPoly3 MACRO xval0, elct:=<?>, x0:=<0>, xstep:=<1>
LOCAL is, p3, p3Type, oa, xval, inx, tmpxs, tmpx0, destType
  is INSTR <xval0>, <:>
  xval SUBSTR <xval0>, is+1
  if is eq 2
	inx SUBSTR <xval0>, 1, 1
  else
	inx equ <0>
  endif
  p3Type CATSTR <p3t>, %inx
  p3 equ <[edx.MbPOLY]>
  is INSTR xval, <-0>	; numerical array?
  if is
	push ecx
	push edi
	mov edi, NumArrTable[4*xval]	; ID passed
	ifidn <elct>, <?>
		mov edx, [edi-8]	; #elements
		sar edx, 1
		push edx
	else
		push elct
	endif
	mov edx, offset MbPoly3[MbPOLY*inx]	; ptr to a0/a1/a2 for this slot
	fldAny xstep	; increment
	fldAny x0	; start val
	xor ecx, ecx
	destType equ <REAL4>
	.Repeat
		fld st
		if stLastType eq MbReal4
			fst REAL4 PTR [edi+8*ecx]	; set X
			gp3 p3Type
			fstp REAL4 PTR [edi+8*ecx+4]
		elseif stLastType eq MbReal8
			fst REAL8 PTR [edi]
			gp3 p3Type
			fstp REAL8 PTR [edi+8]
			add edi, 16
		else
			fist DWORD PTR [edi+8*ecx]
			gp3 p3Type
			fistp DWORD PTR [edi+8*ecx+4]
		endif
		fadd st, st(1)
		inc ecx
	.Until ecx>=stack
	fstp st	; discard x0
	fstp st	; and xstep
	pop eax
	pop edi
	pop ecx
	EXITM <>	; no retval
  else
	fldAny xval
	mov edx, offset MbPoly3[MbPOLY*inx]	; ptr to a0/a1/a2 for this slot
	gp3 p3Type
	EXITM <ST(0)>	; return single value
  endif
ENDM
GfAdd=	0	; create new array
GfDirs=	0	; get files, not folders
; user-definable flags:
GfNoPaths=	0	; 0=include full paths, default; 1=file names only
GfNoRecurse=	0	; 0=include subfolders, default; 1=current or path only
GfNoUtf8=	0	; 1=store Files$() ... Lg$() as plain ANSI
GetFolders MACRO fsFolder$:=<*>
  GfDirs=08000000h	; bit 27
  GetFiles fsFolder$
ENDM
AddFolders MACRO fsFolder$:=<*>
  GfDirs=08000000h	; bit 27
  GfAdd=80000000h	; bit 31 set
  GetFiles fsFolder$
ENDM
AddFiles MACRO args:VARARG
  GfAdd=80000000h	; bit 31 set
  GetFiles args
ENDM
FindInFileP equ FindInFile
FindInFileP$ equ <FindInFileP>
GetFiles MACRO fsFiles$, fsStart$:=<>, fsEnd$:=<1>, fsMode:=<0>	; fsMode bitwise: End$: 0=to end of line, 1=whole line, Start+End$: 4=fullword, 8=8k,16=65k
LOCAL c34, dot, nustr, tmp$, gfSearch
  if MbUseErrLine
	mov MbErrLine, @Line
  endif
  dot=0
  ifidni <fsFiles$>, <CL>
	dot=1
  endif
  ifidni <fsFiles$>, <wCL>
	dot=2
  endif
  if dot
	push esi
	push edi
	push ebx
	push ecx
	if dot eq 111	; disactivated 3/16
		xchg CL$(), esi
		.if !esi
			xchg CL$(0), esi
		.endif
	else
		xor esi, esi	; default: 0 files
		.if wCL$()
			xchg Utf8$(eax), esi
		.endif
	endif
	Dim Files$(new:0)
	xor ebx, ebx
	.if esi
		mov edi, esi
		mov cl, 32		; default: space
		lodsb
		.if al==34
			inc ecx
			inc ecx		; set delimiter to quote
			inc edi
		.endif
		.Repeat
			lodsb
			.if al==cl || !al	; end of filename
				mov byte ptr [esi-1], 0
				Let Files$(ebx)=edi
				void Exist(edi)
				GfSetInfo ebx, GfLastWrite(-1)
				inc ebx
				.Repeat
					lodsb	; first byte after nullbyte
				.Until al>34 || !al
				mov cl, [esi-2]
				.if !cl
					mov cl, 32
				.endif
				mov edi, esi
				dec edi
			.endif
		.Until !al
	.endif
	xchg eax, ebx
	mov MbGetFileCount, eax
	pop ecx
	pop ebx
	pop edi
	pop esi
	EXITM
  endif
  ifidn <fsFiles$>, <WM_DROPFILES>
	push edi
	push ebx
	call MbBufferGet
	xchg eax, edi
	lea eax, [edi+32768]
	push 1
	push eax
	call MbBufferFix
	xor ebx, ebx
	Dim Files$(new:0)
	.While 1
		invoke DragQueryFileW, wParam, ebx, edi, 32767
		.Break .if !eax
		void Utf8$(edi)
		Let Files$(ebx)=eax
		void wExist(edi)
		GfSetInfo ebx, GfLastWrite(-1)
		inc ebx
	.Endw
	invoke DragFinish, wParam
	xchg eax, ebx
	mov MbGetFileCount, eax
	pop ebx
	pop edi
	EXITM
  endif
  c34 INSTR <fsFiles$>, <">
  ife c34
	c34 INSTR <fsFiles$>, <'>
  endif
  gfSearch = 0
  ifnb <fsStart$>
	gfSearch = 20000000h	; bit 29
	ifidn <fsStart$>, <0>
		tmp$ CATSTR <## Invalid arg in line >, %@Line, < ##>
		% echo tmp$
		.err
	else
		push fsMode
		if (opattr fsEnd$) eq atImmediate
			ifidn @SubStr(<fsEnd$>, 1, 1), <">
				push repargA(fsEnd$)	;; aka FifLinesPerFile if not a string
			elseif (fsEnd$ lt -1) or (fsEnd$ ge 127)
				echo GetFiles: MaxLine=-1...126
				.err
			else
				push fsEnd$	;; repargA no good for immediate numbers
			endif
		else
			push repargA(fsEnd$)	;; aka FifLinesPerFile if not a string
		endif
		push repargA(fsStart$)
	endif
  endif
  dot INSTR <fsFiles$>, <.>
  ife dot
	dot INSTR <fsFiles$>, <*>
  endif
  if (dot gt 0) and (c34 eq 0)	;; not an offset or a var
	.DATA
	tmp$ CATSTR <nustr db ">, <fsFiles$>, <", 0>
	tmp$
	.CODE
	push offset nustr
  else
	push repargA(fsFiles$)	;; e.g. *.asc
  endif
  if GfNoRecurse
	GfNoRecurse = 10000000h	; bit 28
  endif
  if GfNoPaths
	GfNoPaths=40000000h	; bit 30
  endif
  push GfDirs or GfAdd or gfSearch or GfNoPaths or GfNoRecurse
  GfDirs=FILE_ATTRIBUTE_NORMAL	; reset two
  GfAdd=0					; flags
  call FindInFileP$		; GetFiles proc, returns UTF-8 string array
ENDM
SortFiles MACRO dsmode, dax	; use after GetFiles
LOCAL mode, dsm$, dax$
  dsm$ CATSTR <dsmode>, <date>	; blank means date
  dsm$ SUBSTR dsm$, 1, 4
  dax$ CATSTR <dax>, <xxx>
  dax$ SUBSTR dax$, 1, 3
  ifidni dsm$, <date>
	if Uzi
		push ecx
		xor ecx, ecx
		sub esp, QWORD
		.Repeat
			void GfLastWrite(ecx)
			movhps qword ptr [esp], xmm0
			mov [esp], ecx
			movhps xmm0, qword ptr [esp]
			GfSetInfo ecx, xmm0
			inc ecx
		.Until ecx>=MbGetFileCount
		add esp, QWORD
		pop ecx
	endif
	mode=16
	mov edx, offset MbArrTable-24
	ifidni dax$, <asc>
		mode=mode or 64
	endif
	invoke MbArrSort, [edx], MbGetFileCount, [edx+28], mode
  elseifidni dsm$, <size>
	if Uzi
			tmp$ CATSTR <## line >, %@Line, <: can't sort zips by size ##>
			% echo tmp$
			.err
	endif
	mov edx, offset MbArrTable-24
	mov eax, [edx]	; add stack, 8 same size
	mode=16 or 128	; Swap16
	add eax, 8
	ifidni dax$, <asc>
		mode=mode or 64
	endif
	invoke MbArrSort, eax, MbGetFileCount, [edx+28], mode
  elseifidni dsm$, <name>
	if Uzi
			tmp$ CATSTR <## line >, %@Line, <: can't sort zips by name ##>
			% echo tmp$
			.err
	endif
	dsm$ CATSTR <## Warning: file size and date invalid below line >, %@Line, < ##>
	% echo dsm$
	push MbGetFileCount
	ifidni dax$, <asc>
		push -1
	else
		push 1
	endif
	call MbQSortP
  else
	.err <invalid args &dsmode>
  endif
ENDM
GfCallback MACRO arg:=<0>
  mov MbGetFileCount[16], arg 	; ffxCallback
ENDM
GfDTP$ equ GfDateTimeP
GfDTP$ PROTO :DWORD, :DWORD
GfSetInfo MACRO index:=<-1>, arg	; set filesize (hi qword) and FILETIME (lo qword xmm0)
  push -111
  push index
  call GfDTP$
ENDM
@DtfP macro pST
LOCAL c3$, tmp$
  c3$ CATSTR <pST>, <xx>
  c3$ SUBSTR c3$, 1, 3
  if @InStr(1, <pST>, <[EL:>)
	if stSizeG eq FILETIME
		movlps xmm0, FILETIME ptr [VarPtr(pST)]
		push 127
	else
		push VarPtr(pST)
	endif
  elseifidni c3$, <xmm>
	ifdifi <pST>, <xmm0>
		tmp$ CATSTR <## line >, %@Line, <, >, <pST>, <: only xmm0 allowed ##>
		% echo tmp$
		.err
	endif
	push 127
  else
	if opattr(pST) eq atImmediate
		if (pST gt 126) or (pST lt -128)
			tmp$ CATSTR <## line >, %@Line, <: >, @signed$(pST), < not possible, legal offsets are -128..+126 ##>
			% echo tmp$
			.err
		endif
	endif
	push pST
  endif
ENDM
GfLastWrite MACRO index:=<-1>	; 100ns intervals of FILETIME returned in xmm0
  push edx
  push 8
  push index
  call GfDTP$
  pop edx
  EXITM <xmm0>
ENDM

GfGetInfo MACRO arg:=<-1>
LOCAL tmp$
  mov eax, offset wfd
  movhps xmm0, qword ptr [eax.WIN32_FIND_DATAW.nFileSizeHigh]
  ifidni <arg>, <c>
	movlps xmm0, qword ptr [eax.WIN32_FIND_DATAW.ftCreationTime]
  elseifidni <arg>, <m>
	movlps xmm0, qword ptr [eax.WIN32_FIND_DATAW.ftLastWriteTime]
  elseifidni <arg>, <a>
	movlps xmm0, qword ptr [eax.WIN32_FIND_DATAW.ftLastAccessTime]
  else
	tmp$ CATSTR <## line >, %@Line, <: allowed args are c=created, m=modified and a=accessed, always for last exi>, <st(file$) ##>
	% echo tmp$
	.err <## returned xmm0 can be used with GfSetInfo to modify the last write values ##>
  endif
  EXITM <xmm0>
ENDM

GfAgeMs MACRO index:=<-1>
  push 9
  push index
  call GfDTP$
  EXITM <eax>
ENDM

GfAgeSeconds MACRO  index:=<-1>
  push 10
  push index
  call GfDTP$
  EXITM <eax>
ENDM
GfAgeSecs MACRO index:=<-1>
  push 10
  push index
  call GfDTP$
  EXITM <eax>
ENDM

GfAgeMinutes MACRO index:=<-1>
  push 11
  push index
  call GfDTP$
  EXITM <eax>
ENDM

GfAgeHours MACRO index:=<-1>
  push 12
  push index
  call GfDTP$
  EXITM <eax>
ENDM

GfSize MACRO index:=<-1>
  push 0			; 0=size
  push index
  call GfDTP$
  EXITM <eax>		; hi DWORD in edx
ENDM

GfDtFormat macro dtfSlot, dtfArg
  ExternDef DtFormat:DWORD
  mov DtFormat[4*dtfSlot], repargA(dtfArg)
ENDM

useUTC=0	; GfDate, GfTime$
GfDate$ MACRO index:=<-1>, GfDTf$
  push 1+256*useUTC			; 1->0, date
  push index
  ifnb <GfDTf$>
	GfDtFormat 0, GfDTf$
  endif
  call GfDTP$
  EXITM emArr$
ENDM

GfTime$ MACRO index:=<-1>, GfDTf$
  push 3+256*useUTC			; 3->2, time
  push index
  ifnb <GfDTf$>
	GfDtFormat 1, GfDTf$
  endif
  call GfDTP$
  EXITM emArr$
ENDM
wGfDate$ MACRO index:=<-1>, GfDTf$
  push 2+256*useUTC			; 2->1, date UC
  push index
  ifnb <GfDTf$>
	GfDtFormat 0, GfDTf$
  endif
  call GfDTP$
  lea eax, [2*eax+1]
  EXITM emArr$
ENDM

wGfTime$ MACRO index:=<-1>, GfDTf$
  push 4+256*useUTC			; 4->3, time UC
  push index
  ifnb <GfDTf$>
	GfDtFormat 1, GfDTf$
  endif
  call GfDTP$
  EXITM emArr$
ENDM
defAgeQW macro
  ifndef ageMultD
	.DATA
	ageMultD dq 864000000000
	ageMultH dq 36000000000
	ageMultM dd 600000000
	ageMultS dd 10000000
	ageMultMs dd 10000
	.DATA?
	MbWeekYear	dd ?
	MbOrdinalDay	dd ?
 	.CODE
  endif
endm
TimeSF MACRO dt$, utc:=<useUTC>
LOCAL tmp$
  push esi
  push edi
  push ecx
  ifndef MbTimeST
    .DATA?
    MbTimeST	SYSTEMTIME <>
	FILETIME <>
	FILETIME <>
    MbTimeFT equ MbTimeST[SYSTEMTIME]
    .DATA
    align 16
    _tsf	QWORD 0FFFF00FFFF00FFFFh	; 01.02.2003 -> 01 02 2003
    .CODE
  endif
  nops 2
  push repargA(dt$)
  nops 2
  mov edi, offset MbTimeST
  if usedeb
	mov ecx, stack
	mov eax, [ecx+2]
	and dword ptr eax, 2e00002eh
	.if eax!=2e00002eh
		.if byte ptr [ecx+4]=="."
			tmp$ CATSTR <MsgBox 0, "Use ANSI format in line >, %@Line, <", "TimeSF:", MB_OK>
			tmp$
		.else
			tmp$ CATSTR <MsgBox 0, Cat$("Bad date format ["+ecx+"] in line >, %@Line, <"), "TimeSF:", MB_OK>
			tmp$
		.endif
	.endif
  endif
  MbXms
  invoke GetLocalTime, edi	; prefill
  pop ecx
  movlps xmm0, qword ptr [ecx]	; dd.mm.xx
  add ecx, 6		; 01.02.2003
  void Val(ecx)
  .if edx==-127
	inc edi	; take current year	
	inc edi
  .else
	mov edx, 1900
	.if eax<edx
		dec ecx
		dec ecx
		.if eax<70
			add eax, 100
		.endif
		add eax, edx
	.endif
	stosw	; wYear
  .endif
  sub esp, 8
  andps xmm0, OWORD PTR _tsf
  movlps qword ptr [esp], xmm0	; now it's writable
  lea eax, [esp+3]
  void Val(eax)
  stosd			; wMonth, 0 for wDayOfWeek
  mov eax, esp
  void Val(eax)
  add esp, 8
  stosw			; wDay
  sub edi, 8
  add ecx, 5		; 01.02.2013, 12:34:56
  and dword ptr [edi.SYSTEMTIME.wSecond], 0	; clear seconds and milliseconds
  .if Val(ecx)<=24
	add ecx, edx
	mov dword ptr [edi.SYSTEMTIME.wHour], eax	; set hour, clear minutes
	void Val(ecx)
	.if edx<=3	; 12:34 or 12:34:56
		add ecx, edx
		mov dword ptr [edi.SYSTEMTIME.wMinute], eax	; set minutes, zero seconds
		.if Val(ecx)<=59
			mov [edi.SYSTEMTIME.wSecond], ax
		.endif
	.endif
  .endif
  lea esi, [edi+SYSTEMTIME]
  ife utc
	invoke TzSpecificLocalTimeToSystemTime, 0, edi, edi
	invoke SystemTimeToFileTime, edi, esi
  else
	invoke SystemTimeToFileTime, edi, esi
	invoke FileTimeToSystemTime, esi, edi	; set dayofweek
  endif
  MbXmr
  movups xmm0, oword ptr [esi]	; fTime
  xchg eax, edi
  pop ecx
  pop edi
  pop esi
  EXITM <xmm0>	; pTimeSF
ENDM
IsoWeek MACRO arg:=<0>
LOCAL oa, back1y, c1$
  FpuSet MbNear64
  defAgeQW
  push esi
  push edi
  push ecx
  push 0
  sub esp, FILETIME+SYSTEMTIME+8-4
  iwft equ [edi.FILETIME]
  iwst equ [esi.SYSTEMTIME]
  IncWeek equ dword ptr [esi+SYSTEMTIME]
  CurDayOfWeek equ dword ptr [esi+SYSTEMTIME+4]
  MbXms
  oa=0
  ifidn <arg>, <(eAx)>
	void TimeSF(arg, 1)	; date$ passed
	mov edi, esp	; arg could be edi, therefore behind tsf
	movlps iwft, xmm0
	lea esi, [edi+FILETIME]	; pSysTime
	invoke FileTimeToSystemTime, edi, esi
  elseifidn <arg>, <xmm0>	; TimeSF passes FT
	mov edi, esp
	lea esi, [edi+FILETIME]
	movlps iwft, xmm0
	invoke FileTimeToSystemTime, edi, esi
  else
	oa INSTR <arg>, <[EL:>
	if oa eq 1
		if stSizeG eq FILETIME
			mov edi, esp
			lea esi, [edi+FILETIME]
			mov edi, VarPtr(arg)
			invoke FileTimeToSystemTime, edi, esi
		else
			.err @CatStr(<## invalid argument in line >, %@Line, < ##>)
		endif
	else
		oa = opattr arg
		c1$ SUBSTR <arg>, 1, 1
		ifidn c1$, <">
			oa=0
		endif
		ifidn c1$, <'>
			oa=0
		endif
		if oa eq atImmediate	; offset -128...+127 passed
			mov edi, esp
			lea esi, [edi+FILETIME]
			invoke GetLocalTime, esi	; now
			invoke SystemTimeToFileTime, esi, edi
		else
			void TimeSF(arg, 1)	; date$ passed
			mov edi, esp
			movlps iwft, xmm0
			lea esi, [edi+FILETIME]
			invoke FileTimeToSystemTime, edi, esi
		endif
	endif
  endif
  fild iwft		; current FILETIME to ST(0)
  if oa eq atImmediate
	if arg
		fild ageMultD
		push arg
		fimul stack	; isw(imm offset days)
		fadd
		fld st
		fistp iwft
		invoke FileTimeToSystemTime, edi, esi
		pop eax
	endif
  endif
  movzx eax, iwst.wDayOfWeek	; m2m pushes a word - bug
  .if !eax
	add eax, 7
  .endif
  mov CurDayOfWeek, eax
back1y:
  inc IncWeek
  m2m eax, 1		; get DayOfWeek for January 1st
  mov dword ptr iwst.wMonth, eax
  mov iwst.wDay, ax
  invoke SystemTimeToFileTime, esi, edi
  invoke FileTimeToSystemTime, edi, esi
  movzx edx, iwst.wYear
  mov MbWeekYear, edx
  dec iwst.wYear
  fild iwft		; Jan1 FT to ST(0)
  fsubr st, st(1)
  fild ageMultD
  fdiv
  push eax
  fist stack
  pop eax
  inc eax
  mov MbOrdinalDay, eax	; OK
  movzx edx, iwst.wDayOfWeek	; Sunday = 0, Monday = 1
  .if !edx
	add edx, 7	; Monday=1 ... Sunday=7
  .endif
  .if eax<=CurDayOfWeek && edx>4	; edx: 27, cd 13
	fstp st
	jmp back1y
  .else
	sub eax, CurDayOfWeek
	.if signed eax>=363 || (signed eax>=360 && edx<=3 && byte ptr iwst.wYear!=227)	; hack for 2020
		push 52*7
		fisub stack
		pop edx
		inc MbWeekYear
	.endif
  .endif
  fisub CurDayOfWeek
  push 11			; OK
  fiadd stack
  fistp stack
  pop eax
  m2m ecx, 7
  cdq
  idiv ecx
  MbXmr
  add esp, FILETIME+SYSTEMTIME+8
  fstp st
  pop ecx
  pop edi
  pop esi
  EXITM <eax>
ENDM
Age MACRO pST:REQ, ageUnit:=<h>	; Age(pSystemTime, d/h/m/s/ms)
LOCAL c2$
  defAgeQW
  c2$ CATSTR <ageUnit>, <o>
  c2$ SUBSTR c2$, 1, 2
  push ecx
  push eax
  push edx
  ffree st(7)
  if @InStr(1, <pST>, <[EL:>)
	if stSizeG eq FILETIME
		void VarPtr(pST)
		fild FILETIME ptr [edx]
	else
		invoke SystemTimeToFileTime, VarPtr(pST), esp
		fild qword ptr [esp]
	endif
  elseifidni <pST>, <xmm0>
	movlps qword ptr [esp], xmm0
	fild qword ptr [esp]
  else
	invoke SystemTimeToFileTime, pST, esp
	fild qword ptr [esp]
  endif
  invoke GetSystemTimeAsFileTime, esp	; current UTC as FT
  fild qword ptr [esp]
  fsubr
  ifidni c2$, <do>
	ffree st(7)
	fild ageMultD
	fdiv
  elseifidni c2$, <ho>
	ffree st(7)
	fild ageMultH
	fdiv
  elseifidni c2$, <mo>
	fidiv ageMultM
  elseifidni c2$, <so>
	fidiv ageMultS
  elseifidni c2$, <ms>
	fidiv ageMultMs
  endif
  fistp qword ptr [esp]
  pop eax
  pop edx
  pop ecx
  EXITM <eax>
ENDM
GetTZ$ MACRO arg:=<$>
LOCAL is
  push ecx
  sub esp, TIME_ZONE_INFORMATION
  invoke GetTimeZoneInformation, esp
  ifidn <arg>, <$>
	is=1
	mov eax, [esp.TIME_ZONE_INFORMATION.Bias]
  else
	is INSTR <arg>, <Name>
	if is
		invoke MbBufferGet
		lea ecx, [esp.TIME_ZONE_INFORMATION.&arg]
		push edi
		xchg eax, edi
		add wLen(ecx), eax
		invoke MbCopy, edi, ecx, eax
		push 1
		push eax
		call MbBufferFix
		pop edi
	else
		movups xmm0, OWORD PTR [esp.TIME_ZONE_INFORMATION.&arg]
	endif
  endif
  add esp, TIME_ZONE_INFORMATION
  pop ecx
  if is eq 1
	EXITM Str$("%+i", eax/-60)
  elseif is
	EXITM emArr$
  else
	EXITM <xmm0>
  endif
ENDM
MbD@=0
MbT@=2
MbDTF$ equ MbDTF
MbDTF$ PROTO :DWORD, :DWORD
fDate$ MACRO pST:=<0>, GfDTf$
  @DtfP pST
  push MbD@
  ifnb <GfDTf$>
	GfDtFormat 0, GfDTf$
  endif
  call MbDTF$
  EXITM emArr$
ENDM
fTime$ MACRO pST:=<0>, GfDTf$
  @DtfP pST
  push MbT@
  ifnb <GfDTf$>
	GfDtFormat 1, GfDTf$
  endif
  call MbDTF$
  EXITM emArr$
ENDM
fSize$ MACRO arg
  push eax
  push edx
  movhps qword ptr [esp], xmm0
  pop edx
  pop eax
  EXITM Str$(edx::eax)
ENDM 
wfDate$ MACRO pST:=<0>, GfDTf$
LOCAL c3$
  c3$ CATSTR <pST>, <xx>
  c3$ SUBSTR c3$, 1, 3
  if @InStr(1, <pST>, <[EL:>)
	push VarPtr(pST)
  elseifidni c3$, <xmm>
	push 127
  else
	push pST
  endif
  push MbD@+1
  ifnb <GfDTf$>
	GfDtFormat 0, GfDTf$
  endif
  call MbDTF$
  EXITM emArr$
ENDM
wfTime$ MACRO pST:=<0>, GfDTf$
LOCAL c3$
  c3$ CATSTR <pST>, <xx>
  c3$ SUBSTR c3$, 1, 3
  if @InStr(1, <pST>, <[EL:>)
	push VarPtr(pST)
  elseifidni c3$, <xmm>
	push 127
  else
	push pST
  endif
  push MbT@+1
  ifnb <GfDTf$>
	GfDtFormat 1, GfDTf$
  endif
  call MbDTF$
  EXITM emArr$
ENDM
wfSize$ MACRO arg
  push eax
  push edx
  movhps qword ptr [esp], xmm0
  pop edx
  pop eax
  EXITM wStr$(edx::eax)
ENDM 
FileGetSel MACRO index
  movd eax, GfLastWrite(index)
  test al, 1
  EXITM <Zero?>
ENDM

FileSetSel MACRO index, sel	; sets an odd/even flag in Files$(index)
  ifndef fsOR
	.DATA
	align 16
	fsOR	OWORD 1
	fsAND	OWORD -2
	.CODE
  endif	
  andps GfLastWrite(index), fsAND
  if (opattr sel) eq atImmediate
	if not sel and 1
		orps xmm0, fsOR
	endif
  else
	.if !(sel & 1)
		orps xmm0, fsOR
	.endif
  endif
  GfSetInfo index, xmm0
ENDM
GetHashRev=0
GetHash MACRO pMem, lMem:=<-1>, hashType:=<md5>
Local tmp$, isFr
  ALG_CLASS_HASH = 4 shl 13			; missing constant
  MbMD5 PROTO :DWORD, :DWORD, :DWORD
  ifidni <hashType>, <md5>
	tmp$ equ <CALG_MD5>
  elseifidni <hashType>, <sha>
	tmp$ equ <CALG_SHA>
  else
	tmp$ CATSTR <## line >, %@Line, <: allowed types are MD5 and SHA ##>
	% echo tmp$
	.err
	tmp$ equ <0>
  endif
  isFr=0
  ifidn <pMem>, <Use_Let>
	if @Line eq frLine
		isFr=1
	endif
  endif
  push tmp$
  if isFr
	push LastFileSize
	Let eax=pMem
	push eax
  else
	ifidn <lMem>, <-1>
		ifidni <pMem>, <eax>
			tmp$ CATSTR <## line >, %@Line, <: can't use Len(eax) ##>
			% echo tmp$
			.err
		else
			push Len(pMem)
		endif
	else
		push lMem
	endif
	push repargA(pMem)
  endif
  call MbMD5
  if GetHashRev
	push ecx
	mov cl, 3
	.Repeat
		movd eax, xmm0
		bswap eax
		push eax
		pshufd xmm0, xmm0, 00111001b
		dec cl
	.Until Sign?
	movups xmm0, oword ptr [esp]
	add esp, OWORD
	pop ecx
	ifidni <hashType>, <sha>
		bswap edx
	endif
  endif
  EXITM <eax>	; test for errors - the hash value is in xmm0
ENDM
MbRegValRTE = 1	; default: trigger a run-time error
GetRegKeyArray MACRO stringX:REQ, array:REQ, arraySystime:=<0>
Local is
  if @InStr(1, <array>, <$>)
	Dim array
  endif
  is InStr <arraySystime>, <)>
  if is
	Dim arraySystime As FILETIME
  endif
  @CatStr(<MbRegKey 4, >, <stringX>, <, >, <array>, <,>, arraySystime)
ENDM
GetRegArray MACRO stringX:REQ, array:REQ, arrayData:=<0>
  if @InStr(1, <array>, <$>)
	Dim array
  endif
  if @InStr(1, <arrayData>, <$>)
	Dim arrayData
  endif
  @CatStr(<MbRegKey 5, >, <stringX>, <, >, <array>, <,>, %arrayData)
ENDM
SetReg64 MACRO arg:=<64>
  ExternDef MbRk64:DWORD
  ifidn <arg>, <64>
	or MbRk64[1], 1	; KEY_WOW64_64KEY
  elseifidn <arg>, <32>
	and MbRk64[1], 0
  else
	m2m MbRk64, arg
  endif
ENDM

rkProc equ <RegKeyP>
MbRegKey macro rkMode:REQ, stringX:REQ, rkVal:REQ, rkNew:REQ
LOCAL is, isbs, HKey, HKeyCode, string
  rkProc PROTO :DWORD, :DWORD, :DWORD, :DWORD
  is INSTR <stringX>, <HK>
  if is
	isbs INSTR <stringX>, <\>
	ife isbs
		isbs INSTR 3, <stringX>, <">
		HKey SUBSTR <stringX>, is, isbs-is	; "HKCR"
		string equ <0>
	else
		HKey SUBSTR <stringX>, is, isbs-is
		string SUBSTR <stringX>, isbs+1
		string CATSTR <">, string
	endif
	is INSTR <HKCR#HKCU#HKLM#HKCC#HKU>, HKey
		if is
			HKeyCode = (is-1)/5		; 1, 6, 11->0, 1, 2
		else
			HKeyCode = HKey
		endif
  elseif (opattr stringX) eq atRegister
	HKeyCode = 7	; must search
	ifidn <stringX>, <(eAx)>
		string equ <MbCat$>
	else
		string equ <stringX>
	endif
  else
	HKeyCode = 1	; default: HKEY_CURRENT_USER
	string equ <stringX>
  endif
  if rkMode ge 4
	push rkNew
	push rkVal
	push repargA(string)
	push HKeyCode*16+rkMode	; enum
	call rkProc
	EXITM
  endif
  tmp$ SUBSTR <rkNew>, 1, 1
  is INSTR <"'(>, tmp$	; MB ret strings are often ( eax )
  if is
	is = 1
	push repargA(rkNew)	; dword or string to set, or default string value
  else
	push rkNew	; immediate or register: assume REG_DWORD
  endif
  push repargA(rkVal)	; dword or string to get
  push repargA(string)	; HKxx\Key
  push HKeyCode*16+2*is+rkMode	; HKEY..., set or get
  rvRegKey	equ <MbFlags[20]>
  rvRegQuery	equ <MbFlags[24]>
  call rkProc
  if MbRegValRTE
	is=rkMode
	ifidn <rkNew>, <-127>
		is=1	; no defval with get, error
	endif
	if is
		mov MbErrLine, @Line
		Externdef MbError10:NEAR
		test edx, edx
		je MbError10
	endif
  endif
ENDM
GetRegVal MACRO stringX:REQ, rkVal:=<0>, rkDef:=<-127>
LOCAL tmp$
  tmp$ CATSTR <MbRegKey 0, >, <stringX>, <, >, <rkVal>, <, >, <rkDef>
  % tmp$
  EXITM emArr$	; eax is dword retval or pointer to MbBuffer
ENDM
SetRegVal MACRO stringX:REQ, rkVal:REQ, rkNew:REQ
LOCAL tmp$
  tmp$ CATSTR <MbRegKey 1, >, <stringX>, <, >, <rkVal>, <, >, <rkNew>
  % tmp$
ENDM
DocFolder$ MACRO dummy
  EXITM GetRegVal("HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders", "Personal")
ENDM
PickFont MACRO addrFnt, hCtrl:=<0>
  MbFnt PROTO :DWORD, :DWORD
  invoke MbFnt, addrFnt, hCtrl
ENDM

; MakeFont hHandFont, Height:40, Underline:TRUE, "Lucida Handwriting"
; MakeFont hVertFont, Height:32, Escapement:900, PitchAndFamily:FF_ROMAN
MakeFont MACRO dest, args:VARARG
LOCAL is, tmp$, argname, argval, fontname
  ifndef dest
	.DATA?
	dest dd ?
	.CODE
  endif
  ifndef MbLogFont
	.DATA?
	MbLogFont LOGFONT <?>
	.CODE
  endif
  % isArr INSTR <dest>, <[Edx>
  if isArr
	push edx
  endif
  mov edx, offset MbLogFont
  push ecx
  FOR arg, <args>
	is INSTR <arg>, <:>
	if is
		argname SUBSTR <arg>, 1, is-1
		argval SUBSTR <arg>, is+1
		ifidni argval, <edx>
			.err <You cannot use edx in MakeFont, sorry>
		endif
		argtmp CATSTR <LOGFONT.lf>, argname
		if (opattr argval) eq atRegister
			tmp$ CATSTR <mov [edx.LOGFONT.lf>, argname, <], >, argval
		elseif (argval LT 127) and (SIZEOF argtmp eq 4)		;; saves 2 bytes per dword field
			push argval
			tmp$ CATSTR <pop [edx.LOGFONT.lf>, argname, <]>
		else
			tmp$ CATSTR <mov [edx.LOGFONT.lf>, argname, <], >, argval
		endif
		tmp$
	else
		is INSTR 2, <arg>, <">
		ife is
			.err <MakeFont error>
		endif
		.DATA
		fontname db arg, 0
		.CODE
			push esi
			push edi
			mov esi, offset fontname
			lea edi, [edx+LOGFONT.lfFaceName]
			push SIZEOF fontname
			pop ecx
			rep movsb
			pop edi
			pop esi
	endif
  ENDM
  invoke CreateFontIndirect, edx
  pop ecx
  ifidni <dest>, <stosd>
	stosd
  else
	if isArr
		pop edx
	endif
	mov dest, eax
  endif
ENDM
SendControlKey MACRO hWin, vKey	; e.g. SCK hwin, VK_V for pasting
  ifndef sckMap
	.DATA?
	sckMap dq 32 dup(?)	; 256/8
	.CODE
  endif
  pushad
  mov esi, hWin
  xchg rv(GetWindowThreadProcessId, esi, 0), ebx
  push FALSE
  push ebx
  push rv(GetCurrentThreadId)
	invoke AttachThreadInput, eax, ebx, TRUE
	mov edi, offset sckMap
	mov byte ptr [edi+VK_CONTROL], 80h
	invoke SetKeyboardState, edi
	invoke SendMessage, esi, WM_KEYDOWN, vKey, 1
	invoke SendMessage, esi, WM_KEYUP, vKey, 0C0000001h
	mov byte ptr [edi+VK_CONTROL], 0
	invoke SetKeyboardState, edi
  call AttachThreadInput	; invoke AttachThreadInput, eax, ebx, FALSE
  invoke SendMessage, esi, WM_ACTIVATE, WA_CLICKACTIVE, 0
  popad
ENDM
Sel$ MACRO hRich, rgStart, rgEnd
  push edi
  call MbBufferGet
  xchg eax, edi
  ifb <rgStart>
	sub esp, TEXTRANGE
	invoke SendMessageW, hRich, EM_EXGETSEL, 0, esp
	mov [esp.TEXTRANGE.lpstrText], edi
  else
	push edi
	push rgEnd
	push rgStart
  endif
  invoke SendMessageW, hRich, EM_GETTEXTRANGE, 0, esp
  add esp, TEXTRANGE
  lea edi, [edi+2*eax]
  push 1
  push edi
  call MbBufferFix
  push eax
  MbUtf8 PROTO
  call MbUtf8
  pop edi
  EXITM emArr$
ENDM
wSel$ MACRO hRich, rgStart, rgEnd, ReAnsi, ReDest:=<0>
  ifnb <rgEnd>
	ifidni <ReAnsi>, <ansi>
		push ReDest
		push rgEnd
		push rgStart
		push hRich
		ReRgP PROTO :DWORD, :DWORD, :DWORD, :DWORD
		call ReRgP
		ifidn <ReDest>, <0>
			EXITM <( eAx)>
		else
			EXITM <ReDest>
		endif
	endif
	push edi
	push edi
	push rgEnd
	push rgStart
  else
	push edi
	sub esp, TEXTRANGEW
	invoke SendMessage, hRich, EM_EXGETSEL, 0, esp
  endif
  call MbBufferGet
  xchg eax, edi
  mov [esp.TEXTRANGEW.lpstrText], edi
  invoke SendMessageW, hRich, EM_GETTEXTRANGE, 0, esp
  add esp, TEXTRANGEW
  lea edi, [edi+2*eax]
  push 1
  push edi
  call MbBufferFix
  pop edi
  EXITM <( eAx)>
ENDM
wWin$ MACRO h1, cHandle
  if usedeb
	if (opattr h1) eq 98
		tmp$ CATSTR <** Warning: Win$ handle is local: >, <h1>, < in line >, %@Line, < **>
		% echo tmp$
	endif
  endif
  ifnb <cHandle>
	push ecx
	invoke GetDlgItem, h1, cHandle
	pop ecx
	invoke MbWinStrP, 1, eax
  else	
	invoke MbWinStrP, 1, h1
  endif
  EXITM <( eAx)>
ENDM

Win$ MACRO h1, cHandle
  if usedeb
	if (opattr h1) eq 98
		tmp$ CATSTR <** Warning: Win$ handle is local: >, <h1>, < in line >, %@Line, < **>
		% echo tmp$
	endif
  endif
  ifnb <cHandle>
	ifidn <cHandle>, <sci>
		invoke MbWinStrP, 100h, h1
	elseifidn <cHandle>, <xxl>
		push esi
		push edi
		push ebx
		push ecx
		mov esi, h1
		ifndef MbWinXXL$
			.DATA?
			MbWinXXL$ dd ?
			.CODE
		endif
		Clr$ MbWinXXL$
		invoke SendMessage, esi, WM_GETTEXTLENGTH, 0, 0
		xchg eax, ebx
		.if signed ebx<=0
			mov edi, offset MbArrEmpty
		.else
			push 0
			inc ebx
			push ebx
			call MbNewP
			xchg eax, edi
			invoke SendMessage, esi, WM_GETTEXT, ebx, edi
		.endif
		mov MbWinXXL$, edi
		pop ecx
		pop ebx
		pop edi
		pop esi
		EXITM <MbWinXXL$>
	else
		push ecx
		invoke GetDlgItem, h1, cHandle
		pop ecx
		invoke MbWinStrP, 0, eax
	endif
  else	
	invoke MbWinStrP, 0, h1
  endif
  EXITM <( eAx)>
ENDM
_Win$ macro h1, cHandle
  EXITM Win$(h1, cHandle)
ENDM

WinByTitle MACRO arg:REQ, sensitive:=<0>
  push sensitive
  push repargA(arg)
  MbWinGh PROTO
  call MbWinGh
  EXITM <eax>
ENDM

ExeFromWin$ MACRO hWin:REQ, ifn
  ifndef GetModuleFileNameEx
	uselib psapi
  endif
  push edi
  push ecx	; MB ABI
  ifdifi <hWin>, emArr$
	ifdifi <hWin>, <eax>
		mov eax, hWin
	endif
  endif
  push eax		; slot
  push esp		; pRetVal
  push eax		; handle
  call MbBufferGet
  xchg eax, edi	; buffer start
  call GetWindowThreadProcessId
  push [esp]
  push FALSE
  push PROCESS_VM_READ or PROCESS_QUERY_INFORMATION
  call OpenProcess	; inv OP, flags, 0, pID
  .if !eax
	invoke MbCopy, edi, Err$(), -2	; -2 for Cat$
	xchg eax, edi	; push end of buffer
  .else
	push eax	; handle
	ifidni <ifn>, <image>
		invoke GetProcessImageFileName, eax, edi, 4096	; \Device\...\masm32...
	else
		invoke GetModuleFileNameEx, eax, 0, edi, 4096	; x:\Masm32...
	endif
	add edi, eax
	call CloseHandle
  .endif
  push 1
  push edi
  call MbBufferFix
  pop edx			; PID or error
  pop ecx
  pop edi
  EXITM emArr$
ENDM
FindProcess MACRO pName$
  MbFindPro PROTO
  push wRec$(repargA(pName$))
  call MbFindPro
  EXITM <eax>
ENDM
GetProcessArray MACRO arg
  ifndef GetModuleFileNameEx
	uselib psapi
  endif
  ifndef MbProc$
	Dim MbProc$()
	Dim MbProcID() As DWORD  
  endif
  push esi
  push edi
  push ebx
  push ecx
  sub esp, 8000
  mov esi, esp
  push eax
  invoke EnumProcesses, esi, 4000, esp
  push stack		; copy total processes
  xor ebx, ebx		; counter accessible
  call MbBufferGet
  xchg eax, edi	; buffer start
  xor eax, eax
  stosd
  stosd
  .Repeat
	lodsd
	push eax
	mov MbProcID(ebx), eax
	push 0
	sub esp, OSVERSIONINFO-4
	push OSVERSIONINFO
	invoke GetVersionEx, esp
	mov edx, PROCESS_QUERY_INFORMATION	; XP
	.if dword ptr [esp.OSVERSIONINFO.dwMajorVersion]>5
		mov edx, PROCESS_QUERY_LIMITED_INFORMATION
	.endif
	add esp, OSVERSIONINFO
	push edx
	call OpenProcess	; flags, 0, pID
	.if eax
		push eax	; handle
		invoke GetProcessImageFileName, eax, edi, 8000	; \Device\...\masm32...
		mov ecx, [edi-8]
		.if !ecx
			.if Instr_(edi, "\Windows\")
				sub edx, 3
				mov [edi-4], edx
				push edx
				Let [edi-8]=edi
				pop edx
				mov ecx, [edi-8]
				mov byte ptr [ecx+edx+3], 0
			.endif
		.endif
		.if eax
			test ecx, ecx
			mov ecx, edi
			.if !Zero?
				.if Instr_(edi, [edi-8])
				    add ecx, [edi-4]
				    mov word ptr [ecx], ":C"
				.endif
			.endif
			Let MbProc$(ebx)=ecx
			inc ebx
		.endif
		call CloseHandle
	.endif
	dec stack
  .Until Sign?
  Clr$ [edi-8]
  pop edx		; -1
  pop edx		; total processes
  xchg eax, ebx
  add esp, 8000
  pop ecx
  pop ebx
  pop edi
  pop esi
  ifidn <arg>, <?>
	EXITM <eax>
  else
	EXITM <>
  endif
ENDM
GetDevicesArray MACRO arg
  push esi
  push ecx
  call MbBufferGet
  xchg eax, esi
  xor ebx, ebx
  ifndef MbDevices$
	Dim MbDevices$()
  endif
  invoke QueryDosDevice, 0, esi, MbBufSize/4
  xor ecx, ecx
  .Repeat
	Let MbDevices$(ecx)=esi
	.Repeat
		lodsb
	.Until !al
	inc ecx
  .Until [esi]==al
  xchg eax, ecx
  pop ecx
  pop esi
  ifidn <arg>, <?>
	EXITM <eax>
  else
	EXITM <>
  endif
ENDM
App16 MACRO hWnd	; .if App16(hWin)...
	ifdifi <hWnd>, <eax>
		mov eax, hWnd
	endif
	push ecx	; MasmBasic ABI: preserve ecx ;-)
	push eax	; original handle
	push eax	; create a slot
	invoke GetWindowThreadProcessId, eax, esp
	push WinByTitle("WOWExec")	; get a handle and create a slot
	invoke GetWindowThreadProcessId, eax, esp
	pop edx	; ID Wow
	pop ecx	; ID app
	cmp ecx, edx
	pop eax	; we surely need the handle
	pop ecx	; restore a precious register
	EXITM <Zero?>
ENDM
; -------- Clipboard macros -------
HtmlClip$ MACRO MbLimit
  push -125	; CF_HTML
  ifb <MbLimit>
	push MbBufSize/4
  else
	push MbLimit
  endif
  call MbClipP
  EXITM <MbC:>
ENDM

wClip$ MACRO MbLimit
  push CF_UNICODETEXT
  ifb <MbLimit>
	push MbBufSize/4
  elseif (opattr MbLimit) eq atImmediate
	push MbLimit*2
  else
	push MbLimit
	shl stack, 1
  endif
  call MbClipP
  EXITM <MbC:>
ENDM

ifndef CF_RTF
	CF_RTF = -126
endif
; CF_HTML=-125
CF_USER=-127
SetCfUser MACRO arg	; MbSetCF
  mov MbCF, repargA(arg)
  echo ** CF_USER set, use e.g. as SetClip$ "xxx", CF_USER or Print Clip$(CF_USER) **
ENDM

Clip$ MACRO MbLimit:=<MbBufSize/4>, CF_x:=<CF_TEXT>
  if @InStr(1, <MbLimit>, <CF_>)
	push MbLimit	; cf_
	push MbBufSize/4
  else
	push CF_x
	push MbLimit
  endif
  call MbClipP
  EXITM <MbC:>
ENDM

; wSetClip$ "Enter text here="+wCrLf$+wRes$(1201)
wSetClip$ MACRO string, CF_x:=<CF_UNICODETEXT>
  SetClip string, CF_UNICODETEXT
ENDM

MbScAdd=0
SetClip$ equ <SetClip>
SetClip MACRO string, CF_x:=<CF_TEXT>
LOCAL is
  ifidni <string>, <#start>
	.if 1
		MbScAdd=1
  elseifidni <string>, <#end>
		mov eax, offset MbClips
		and dword ptr [eax+8*MbScAdd-8], 0
		push eax
		push eax
		call MbSCP
		MbScAdd=0
	.endif
  else
	ifidni <string>, <( EdX)>
		push CF_UNICODETEXT
		push edx
	else
		push CF_x
		is INSTR <string>, <">
		ife is
			is INSTR <string>, <'>
		endif
		ife is
			is INSTR <string>, <+>
		endif
		ifidn <CF_x>, <CF_BITMAP>
			if is
				push rv(LoadImage, 0, string, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE)
			elseif opattr(string) eq atImmediate
				push rv(LoadBitmap, rv(GetModuleHandle, 0), string)
			else
				push string
			endif
		else
			if is
				ifidn <CF_x>, <CF_UNICODETEXT>
				  push wCat$(string)
				else
				  push Cat$(string)
				endif
			else
				push repargA(string)
			endif
		endif
	endif
	if MbScAdd
		mov edx, offset MbClips[8*MbScAdd-8]
		pop dword ptr [edx+4]	; string
		pop dword ptr [edx]	; format
		MbScAdd=MbScAdd+1
	else
		call MbSCP
  	endif
  endif
ENDM

SetHtmlClip$ MACRO args:VARARG	; see RichMasm\TbSignature.asc
  ifndef CfEx
	.DATA
	CfEx	db "Version:0.9", 13, 10, "StartHTML:00000120", 13, 10, "EndHTML:00000000", 13, 10
			db "StartFragment:00000154", 13, 10, "EndFragment:00000000", 13, 10
			db "SourceURL:about:blank", 13, 10, "<html><body>", 13, 10
			db "<!--StartFragment-->#<!--EndFragment-->", 13, 10
			db "</body>", 13, 10, "</html>", 0
	.CODE
  endif
  push esi
  push ebx
  push ecx
  xor esi, esi		; do not delete any string in esi
  Let esi=args
  .if !Instr_(esi, "StartHTML")	; if the strings has already the tags, don't add them
	mov ebx, Len(esi)
	Let esi =Replace$(offset CfEx, "#", esi)
	m2m ecx, 50
	sub ecx, Len(Str$(ebx+190))
	Let Mid$(esi, ecx)=Str$(ebx+190)
	mov ecx, 96
	sub ecx, Len(Str$(ebx+154))
	Let Mid$(esi, ecx)=Str$(ebx+154)
  .endif
  call MbBufferGet
  invoke MbCopy, eax, esi, -1
  push 1
  push eax
  call MbBufferFix	; sets next slot pointer
  SetClip$ eax, -125
  Clr$ esi
  pop ecx
  pop ebx
  pop esi
ENDM
ClipboardChanged MACRO
  push edi
  mov edi, offset ccnOld
  invoke GetClipboardSequenceNumber
  cmp eax, [edi]
  stosd
  pop edi
  EXITM <!Zero?>
ENDM
Erase MACRO arg
LOCAL tmp$
  if @InStr(1, <arg>, <00>) eq 1
	push arg
	call MbArrayErase		; string array
  elseif @InStr(1, <arg>, <-0>) eq 1
	push arg
	call MbStructErase		; structures: StrucDim
  else
	if @InStr(1, <arg>, <$!(>)
		tmp$ CATSTR <## line >, %@Line, <: Erase >, <arg>, <: no such array ##>
	else
		tmp$ CATSTR <## line >, %@Line, <: Erase >, <arg>, <: syntax error ##>
	endif
	% echo tmp$
	.err
  endif
ENDM

Clr MACRO arg1:REQ, args:VARARG		; usage Clr eax, MyVar1, MyVar2, ...
  Local IsReg
  ifidn <arg1>, emArr$		;; flag array
  	tmp$ CATSTR <## line >, %@Line, <: Use Clr$ *$(n) ##>
	% echo tmp$
	.err
  else
	IsReg = (opattr(arg1)) AND 127
	if IsReg eq 48
		xor arg1, arg1		;; this register trashed
		for arg, <args>
			mov arg, arg1	;; mov MyVar1, eax
		endm
	else
		and arg1, 0			;; 7 bytes
		for arg, <args>
			and arg, 0
		endm
	endif
  endif
ENDM

Clr$ MACRO args:VARARG
Local is, tmp$
  ifidn <args>, emArr$	;; flag array
	push 0	;; MbFreeP
	call MbInsert	;; Clr L$(123): clear an array element (i.e. assign null)
  else
	is INSTR <args>, emArr$
	if is
		tmp$ CATSTR <## no multiple Clr$ for arrays in line >, %@Line, < ##>
		% echo tmp$
		.err
	else
		for arg, <args>
			push arg
			call MbStringErase	; free heap mem
			mov arg, MbNull$
		endm
	endif
  endif
ENDM

CsvTabInfo STRUCT
  ctiArrPtr	dd ?
  ctiLeft$	dd ?
  ctiFlagTab	dd ?
  ctiEndL	dd ?
  ctiStartR	dd ?
  ctiMissing	dd ?
  ctiMagic	dd ?
CsvTabInfo ENDS
Insert MACRO arg, ct:=<1>
LOCAL sc, tmp$
  sc INSTR <arg>, <=>
  if sc
  	tmp$ CATSTR <## line >, %@Line, <: Insert *$(n)="abc" syntax not supported. Use Insert *$(n), then Let *$(n)=...>
	% echo tmp$
	.err
  elseifidn emArr$, <arg>
	ifnb stLastD2
		ife st2DType
			% echo @CatStr(<## line >, %@Line, <: second para ignored, full row inserted ##>)
			push ct
			call MbInsert
		else
		mov ecx, ct
		.if signed ecx>0 && signed [eax.CsvTabInfo.ctiMissing-CsvTabInfo]<0
			MbXms
			pushad
			push ecx	; ct-1
			xchg eax, ebx
			; len<=0: heapalloc (-len+ct), copy left$...ctiEndL, stosb ct 9/,, mbcopy ctiStartR
			; len>0: heaprealloc (len+ct), ..., heapfree 
			mov eax, [ebx.CsvTabInfo.ctiArrPtr-CsvTabInfo]
			mov esi, [eax]				; old string pointer
			mov edi, [eax+4]
			test edi, edi
			.if Sign?
			    neg edi					; recall string
			.endif
			add edi, stack	; ct
			inc edi
			invoke HeapAlloc, MbProHeap, HEAP_ZERO_MEMORY, edi 				; edi=bytes
			call TestRetVal
			pop ecx
			push eax
			push ecx
			xchg eax, edi
			mov ecx, [ebx.CsvTabInfo.ctiEndL-CsvTabInfo]
			sub ecx, esi
			rep movsb
			mov al, 9
			.if [ebx.CsvTabInfo.ctiFlagTab-CsvTabInfo]==MbFlagCsv
				mov al, ","
			.endif
			pop ecx	; ct elements
			rep stosb
			invoke MbCopy, edi, esi, -2
			mov edx, [ebx.CsvTabInfo.ctiArrPtr-CsvTabInfo]
			mov ecx, [edx]	; old pointer
			pop [edx]
			sub eax, [edx]
			mov edi, [edx+4]	; old len
			mov [edx+4], eax
			dec edi
			.if !Sign?
			    invoke HeapFree, MbProHeap, HEAP_ZERO_MEMORY, ecx
			    call TestRetVal
			.endif
			popad
			MbXmr
		.endif
		endif
	else
		push ct
		call MbInsert
	endif
  else
	MbDiChk arg, 0
  endif
ENDM

Delete MACRO arg, ct:=<1>
LOCAL isArray, argx, isCT
  ifidn emArr$, <arg>
	isCT=0
	ifnb stLastD2
		if st2DType	; only preallocated 2D uses mbinsert
			isCT=1
		else
				% echo @CatStr(<## line >, %@Line, <: no second para for one-dimensional array ##>)
				.err
		endif
	endif
	if isCT			; tab or csv
		ifdif <ct>, <1>
			.err @CatStr(<## Delete in line >, %@Line, <: one element at a time ##>)
		endif
		.if eax==[eax.CsvTabInfo.ctiMagic-CsvTabInfo]
			.if signed [eax.CsvTabInfo.ctiMissing-CsvTabInfo]<=0		;; <= is OK here
				pushad
				mov ebx, [eax.CsvTabInfo.ctiArrPtr-CsvTabInfo]
				mov esi, [eax.CsvTabInfo.ctiStartR-CsvTabInfo]		; source
				inc esi
				mov edi, [eax.CsvTabInfo.ctiEndL-CsvTabInfo]		; dest
				.Repeat
				    lodsb
				    stosb
				.Until !al
				sub esi, edi
				.if sdword ptr [ebx+4]<0
				    neg esi
				.endif 
				sub [ebx+4], esi
				popad
			.endif
		.endif
	else
		if (opattr ct) eq atImmediate
			if ct eq -1
				push 80000000h	; delete all
			else
				push -ct
			endif
		elseifidni <ct>, <all>
			push 80000000h
		else
			neg ct
			push ct
		endif
		call MbInsert	; remove a string array element
	endif
  else
	argx equ <arg>
	isArray INSTR argx, <(>
	if isArray
		tmp$ CATSTR <## line >, %@Line, <, undefined array: >, <arg>
		% echo tmp$
		.err
	else
		sc INSTR argx, <r [E>
		ife sc
			sc INSTR argx, <[EL:>
		endif
		if sc
			MbDiChk arg, 1
		else
			push arg
			call MbStringErase			; delete a single string (see also Clr$)
			if ((opattr arg) AND 127) eq 48
				xor arg, arg
			else
				and arg, 0
			endif
		endif
	endif
  endif
ENDM
ArrayMerge MACRO dest, src
LOCAL tmp$
  if dest le 3
	tmp$ CATSTR <## line >, %@Line, <: use AddFiles to merge Files$ arrays ##>
	.err tmp$
  endif
  push esi
  push edi
  push ecx
  mov edi, offset MbArrTable
  push dest
  pop dword ptr [edi-16]	; MbInsert needs dest ID
  mov esi, [edi+4*src]
  mov ecx, [esi.StringArrHeader.numEL]	; required space
  mov edx, [edi+4*dest]
  cmp [edx.StringArrHeader.recHeap], 0	; test is 3 bytes longer
  .if !Zero?
	if MbUseErrLine
		tmp$ CATSTR <Inkey "## Line >, %@Line, <: Recalled array can't be destination of ArrayMerge ##">
		tmp$
		invoke ExitProcess, -123
	else
		INT 3
	endif
  .endif
  mov eax, [edx.StringArrHeader.numEL]	; dest #el = start el in dest array
  push eax
  mov [edi-8], eax	; change hidden current element
  push ecx		; elements required
  call MbInsert
  pop edx			; new start el
  lea eax, [ecx+edx]
  push eax
  mov edi, [edi+4*dest]	; new dest string table
  mov [edi.StringArrHeader.numEL], eax	; new #elements
  mov eax, [esi.StringArrHeader.recHeap]
  .if eax
	and [esi.StringArrHeader.recHeap], 0		; discard Recall src array
	mov [edi.StringArrHeader.recHeap], eax	; dest keeps pointers and will destroy it
  .endif
  lea edi, [edi+8*edx+StringArrHeader]	; start point
  and [esi.StringArrHeader.numEL], 0	; source array loses all strings
  add esi, StringArrHeader	; point to src strings
  dec ecx			; enable Sign?
  .Repeat
	movsd	; pString
	and dword ptr [esi-4], 0	; mark string erased (len will be ignored)
	movsd	; len
	dec ecx
  .Until Sign?
  pop eax			; #elements
  pop ecx
  pop esi
  pop edi
ENDM
MbInsNum PROTO :DWORD, :DWORD
MbInsNum$ equ MbInsNum
MbDiChk macro arg, mode
LOCAL argx, is, is2, tmp$
  ife stCtG
	.err @CatStr(<## line >, %@Line, <: Insert/Delete needs a dynamic array ##>)
  endif
  argx equ <arg>
  sc INSTR argx, <r [E>
  if sc
	push stLastID
	is INSTR argx, <*>
	if is
		is2 INSTR is+1, argx, <*>	; 2nd star
		if is2
			is INSTR argx, <->		; xy(ecx-1)
			ife is
				is INSTR argx, <+>
			endif
			argx SUBSTR argx, is
			tmp$ CATSTR <[>, argx
			lea edx, tmp$
			if stSizeG ne byte
				if stSizeG eq 2
					sar edx, 1
				elseif stSizeG eq 4
					sar edx, 2
				elseif stSizeG eq 8
					sar edx, 3
				else
					tmp$ CATSTR <unknown size in line >, %@Line, <: >, argx
					.err tmp$
				endif
			endif
			if mode
				not edx
			endif
			push edx
		else
			tmp$ SUBSTR argx, sc+7, is-sc-7
			if mode
				mov edx, tmp$
				not edx
				push edx
			else
				push tmp$
			endif
		endif
	else
		is INSTR argx, <]>
		if (is-sc) eq 6
			if mode
				mov edx, stLastArg
				not edx
				push edx
			else
				push stLastArg	; [Edx]
			endif
		else
			is2 INSTR argx, <+>
			if is2
				tmp$ SUBSTR argx, is2+1, is-is2-1
				if mode
					push -tmp$/stSizeG-1
				else
					push tmp$/stSizeG
				endif
			else
				.err
			endif
		endif
	endif
	call MbInsNum$
  else
	sc INSTR <arg>, <[EL:>				; STRUCT: undefined array: [EL:3]
	is INSTR <arg>, <]>
	if sc
		tmp$ SUBSTR <arg>, sc+4, is-sc-4
		push stLastID
		push tmp$
		ifnb immAdd$
			add dword ptr [esp], immAdd$
		endif
		if mode 
			not dword ptr [esp]
		endif
		call MbInsNum$
	else
		tmp$ CATSTR <## line >, %@Line, <, undefined array: >, <arg>
		% echo tmp$
		.err
	endif
  endif
ENDM

Csv2Tab MACRO	; use without args directly after a Recall ... tab
  pushad
  mov ebx, MbArrTable[4*RecallID]
  push [ebx.StringArrHeader.numEL]
  inc [ebx.StringArrHeader.sdim2]	; MbFlagCsv=-121 -> MbFlagTab=-120
  add ebx, StringArrHeader-8
  .Repeat
	add ebx, 8
	mov esi, [ebx]
	mov ecx, [ebx+4]
	neg ecx
	add ecx, esi
	; "field 1","has, commas","and ""quoted text""",right?,"bye bye"
	push esi
	mov edi, esi
	.Repeat
		lodsb
		stosb
		.if al==34	; quote
			.if byte ptr [esi]==34
				.if byte ptr [esi+1]!=","
				    inc esi  	; deal with malformed crap - see inc esi in GetCsv
				.endif
			.endif
			dec edi
			.Repeat
				lodsb
				stosb
			.Until al==34 && [esi]!=al
			dec edi
			mov al, 9
			stosb
			lodsb
		.elseif al==","
			mov byte ptr [esi-1], 9	; convert
		.endif
	.Until esi>=ecx
	xor eax, eax
	stosb
	pop esi
	dec stack
  .Until Zero?
  pop ecx
  popad
ENDM

; Recall "\masm32\Mb2Masm\DimRecall\CountLines.asm", L$(), -1
Recall MACRO filename, arrname, ct:=<-1>, lc:=<0>	; convert text file/在這裡輸入文字 
LOCAL oa, isG, pos, NewArr, nustr, tmp$, an$, st2DRec
  if MbUseErrLine
	mov MbErrLine, @Line	; ten bytes longer
  endif
  if @InStr(1, <arrname>, <-0>) eq 1	;; structure array
	mov edx, [NumArrTable+4*arrname]	;; address of element zero
	if (opattr lc) eq atImmediate	;; push nBytes: count
		ife lc
				imul eax, [edx-8], stSizeG
				push eax	;; #elements*size=(declare+1)*size 
		else
				push lc*stSizeG
		endif
	else
		imul eax, lc, stSizeG
		push eax
	endif
	if (opattr ct) eq atImmediate	;; ct is start element
			if ct gt 0
				add edx, ct*stSizeG
			endif
		else
			imul eax, ct, stSizeG
			add edx, eax
		endif
	push edx	;; push tostr, start
	push @SubStr(<filename>, 2, 1)	;; 0-9
	call MbInputP	;; invoke MbInputP, fnu2, tostr, nBytes
  else
    an$ equ <arrname>	;; we need to expand the string now
    isG INSTR an$, <[ebx.>	;; SetGlobals structure, e.g. Recall #1, MyRectSettings ?
    oa INSTR <arrname>, <$(>	;; new string array?
    ife oa
	oa = (opattr arrname) AND 127
    endif
    if isG
	oa INSTR isG, an$, <+>	;; they all have a +
	an$ SUBSTR an$, isG+5, oa-isG-5	; [ebx.jzSETTINGS+
	push an$		;; we read a DWORD or RECT or whatever
	lea edx, arrname	;; buffer start in LOCAL var...
	push edx
	push @SubStr(<filename>, 2, 1)	;; 0-9
	call MbInputP	;; invoke MbInputP, fnu2, tostr, nBytes
    elseif (oa eq atGlobal) or (oa eq atLocal)	;; structure or dword in data? or on the stack
	push sizeof arrname	;; we read a DWORD or RECT or whatever
	if oa eq atLocal
		lea edx, arrname	;; buffer start in LOCAL var...
		push edx
	else
		push offset arrname	;; ... or in global data
	endif
	push @SubStr(<filename>, 2, 1)	;; 0-9
	call MbInputP	;; invoke MbInputP, fnu2, tostr, nBytes
    else					;; strings
	st2DRec equ <-123>
	pos instr <ct>, <?>
	if pos eq 1	; ?"@="
		ifidn @SubStr(<ct>, 2, 1), <">
			tmp$ CatStr <push ">, @SubStr(<ct>, 4, 1), @SubStr(<ct>, 3, 1), <"-65536*111>
		else
			tmp$ CatStr <push >, @SubStr(<ct>, 2), <-65536*111>
		endif
		tmp$
	elseifidni <ct>, <tab>	; tab-delimited
		st2DRec equ ct	; set csvtab/st2DType
		push -120
	elseifidni <ct>, <csv>	; comma separated values
		st2DRec equ ct
		push -121
	elseifidni <ct>, <linux>	; LF only
		push +120
	elseifidni <ct>, <unix>	; LF only
		push +120
	elseifidn <lc>, <0>
		push 0
	else
		% ifndef lc
			.DATA?
			lc	dd ?
			.CODE
		endif
		push offset lc
	endif
	pos INSTR <arrname>, <$>		; new array, or existing id?
	if pos
		pos INSTR <arrname>, <(>
		if pos
			NewArr SUBSTR <arrname>, 1, pos-1
		else
			NewArr equ arrname
		endif
		RecallID=MbArrCt
		Dim NewArr(st2DRec)
	else
		RecallID=arrname
	endif
	push 0				;; no name
	push RecallID		;; alias MbDimId
	if @InStr(1, <filename>, <#>)
		push @SubStr(<filename>, 2, 1)		;; 0-9
	else
		push repargA(filename)		;; "myfile.txt"
	endif
	call RecallP
    endif
  endif
ENDM

StoreUtf8 MACRO  filename, other:VARARG
  Store @CatStr(<@>, <filename>), other
ENDM
Store MACRO filename, arrname, ct:=<-1>	; sto #n, x$()
LOCAL stL, stR, stAll, tmp$, stFile, oa, tmp$, stKey, isG, isU, sf$
  isU INSTR <filename>, <@>
  stFile SUBSTR <filename>, 2+isU, 1
  sf$ SUBSTR <filename>, 1+isU
  stKey equ <arrname>
  isG INSTR stKey, <[ebx.>	;; SetGlobals structure, e.g. Recall #1, MyRectSettings ?
  stAll INSTR <arrname>, <-0>
  stL INSTR stKey, <[E>	;; stL INSTR <arrname>, <[E> would be easier, but it doesn't work
  if isG or stL or (stAll eq 1)	;; flag structure array
	if stFile gt 7
		echo #0...#7 allowed
		.err
	endif
	if isG
		lea edx, arrname		; single dimension, specific element
		oa INSTR isG, stKey, <+>		;; they all have a +
		tmp$ SUBSTR stKey, isG+5, oa-isG-5	; [ebx.jzSETTINGS+
		Print sf$:tmp$, edx		; needs explicit ct!!
	else
		oa = opattr ct
		if stAll or (stL eq @InStr(1, <arrname>, <[EL:>))	; all or specific record
			stR INSTR <arrname>, <]>
			push stLastID
		if stAll			; start element:
			push 0		; all elements
		else
			push @SubStr(<arrname>, 5, stR-5)	; dest is element #
		endif
			if oa eq atImmediate
				if ct le 0
						if stAll
							push -stFile			; write all remaining records
						else
							push -8-stFile			; write one record
						endif
				else
						push -(ct*8+stFile)			; push count and file # together
				endif
			else
				imul edx, ct, -8		; shortest for reg32 and gloval vars
				sub edx, stFile
				push edx
			endif
			call MbStructCopy
		elseifidn <ct>, <-1>
			.err <## count must be specified>
		else
			lea edx, arrname		; single dimension, specific element
			Print sf$:TYPE(arrname)*ct, edx	; needs explicit ct!!
		endif
	endif
  elseif @InStr(1, <arrname>, <00>) eq 1
	push ct
	if isU or (arrname le 4 and GfNoUtf8 eq 0)	;; Files$ ... LgTb$(id) as Utf8
		push -arrname
	else
		push arrname		; alias MbDimId
	endif
	if @InStr(1, <filename>, <#>)
		push stFile 		;; 0-9
	else
		push repargA(sf$)		;; "myfile.txt"
	endif
	call StoreP
  else
	oa = (opattr arrname) AND 127
	if (oa eq atGlobal) or (oa eq atLocal)		;; structure or dword in data? or on the stack
		if oa eq atLocal
			lea edx, arrname		;; buffer start in LOCAL var...
		else
			mov edx, offset arrname		;; ... or in global data
		endif
		Print filename:TYPE(arrname), edx  	;; needs explicit ct!!
	else
		tmp$ CATSTR <## Invalid array name in line >, %@Line, <: &arrname& ##>
		% echo tmp$
		.err
	endif
  endif
ENDM

; AxJJStrLen5_s:	; credits for this algo go to Alex alias Antariy
Len MACRO ptr:REQ
  ifidn <ptr>, emArr$
	xchg eax, edx
	test eax, eax
	.if Sign?
		neg eax
	.endif
  else
	push repargA(ptr)
	call MbStrLen
  endif
  EXITM <eax>
ENDM

wLen MACRO ptr:REQ
  push repargA(ptr)
  call MbStrLenW
  EXITM <eax>
ENDM

uLen MACRO arg
  push esi
  push edx
  ifdifi <esi>, <arg>
	mov esi, repargA(arg)
  endif
  xor edx, edx
  .While 1
	lodsb
	.Break .if !al
	inc edx
	.if al>=10000000b	; 128
		inc esi
		.if al>=11100000b
			inc esi
			.if al>=11110000b
				inc esi
				.if al>=11111000b
				    inc esi
				.endif
			.endif
		.endif
	.endif
  .Endw
  xchg eax, edx
  pop edx
  pop esi
  EXITM <eax>
ENDM
r4 MACRO arg	; usage: invoke MyProc, r4(123.456=xxx); select red part, press F1
LOCAL is
  is INSTR <arg>, <=>
  if is
	EXITM @SubStr(<arg>, is+1)
  else
	EXITM <arg>
  endif
ENDM

r8 MACRO arg	; same as r4, but trashes edx::eax
LOCAL is, slash
  is INSTR <arg>, <=>
  slash INSTR <arg>, </>
  if is
	mov edx, @SubStr(<arg>, is+1, slash-is-1)
  endif
  mov eax, @SubStr(<arg>, slash+1)
  EXITM <edx::eax>
ENDM

xOpattr macro arg
LOCAL oa, xreg, tmp$
  oa = (opattr arg) AND 127
  if oa eq atRegister
	xreg SUBSTR <arg>, 1, 1
	ifidni xreg, <x>
		oa=atXmm
	endif
  endif
  EXITM %oa
ENDM

Qcmp MACRO ow0, ow1
	qoCmp qWORD, ow0, ow1
ENDM
Ocmp MACRO ow0, ow1
	qoCmp oWORD, ow0, ow1
ENDM
oqDeb=0	; for testing
oqCt=0
qoCmp macro MbcmpO, ow0, ow1
LOCAL oa0, oa1, xt0, xt1, xt2, movX, ptrX, tmpX, tmp32, tmp8
 if MbcmpO eq QWORD
	movX equ movq	; movLps
	ptrX equ QWORD ptr
 else
	movX equ movUps
	ptrX equ OWORD ptr
 endif
  xt0 equ xmm0
  xt1 equ xmm1
  xt2 equ xmm2
  ifidni <ow0>, <xmm2>	; oc xmm2, any
	xt2 equ <xmm0>
	xt0 equ <xmm2>
  elseifidni <ow1>, <xmm2>	; oc any, xmm2
	xt2 equ <xmm1>
	xt1 equ <xmm2>
  elseifidni <ow0>, <xmm1>	; oc xmm1, any
	xt0 equ xmm1
	xt1 equ xmm0
  elseifidni <ow1>, <xmm0>	; oc any, xmm0
	xt0 equ xmm1
	xt1 equ xmm0
  endif
  oa0 = xOpattr(ow0)
  oa1 = xOpattr(ow1)
  ifdifi <ow0>, xt0
	if oa0 eq atXmm
		movups xt0, ow0
	elseif oa0 eq atRegister
		movX xt0, ptrX [ow0]
	else
		movX xt0, ptrX ow0
	endif
  endif
  ifdifi <ow1>, xt1
	if oa1 eq atXmm
		movups xt1, ow1
	elseif oa1 eq atRegister
		movX xt1, ptrX [ow1]
	else
		movX xt1, ptrX ow1
	endif
  endif
  movaps xt2, xt0	; copy for pcmpeqb
  pcmpeqb xt2, xt1
  pmovmskb edx, xt2	; show in dx where xt0 differs to xt1
  if MbcmpO eq QWORD
	not dl
	and edx, 07fh
  else 			; don't duplicate MSB
	xor edx, -1
	and edx, 07fffh
  endif
  if (oa0 eq atXmm) or (oa1 eq atXmm)
	bsr eax, edx
	sub esp, 16
	movX ptrX [esp], xt0
	movzx edx, byte ptr [esp+MbcmpO-1]	; MSB 0
	bswap edx
	mov dl, byte ptr [esp+eax]	; LSB 0
	movX ptrX [esp], xt1
	movzx eax, byte ptr [esp+eax]	; LSB 1
	bswap eax
	mov al, byte ptr [esp+MbcmpO-1]	; MSB 1
	bswap eax
	add esp, 16
	cmp edx, eax
  else
	bsr edx, edx
	tmpX=1
	ifidni <ecx>, <ow0>
		ifidni <ebx>, <ow1>
			tmpX=2
		endif
	elseifidni <ecx>, <ow1>
		ifidni <ebx>, <ow1>
			tmpX=2
		endif
	else
		tmpX=0
		tmp32 equ <ecx>
		tmp8 equ <cl>
	endif
	if tmpX
		tmp32 equ <ebx>
		tmp8 equ <bl>
		if tmpX eq 2
			.err @CatStr(<## line >, %@Line, <: can't use both ebx and ecx ##>)
		endif
	endif
	push tmp32
	if oa0 eq atRegister
		movzx tmp32, byte ptr [ow0+MbcmpO-1]
		bswap tmp32
		mov tmp8, byte ptr [ow0+edx]
	else
		movzx tmp32, byte ptr ow0[MbcmpO-1]
		bswap tmp32
		mov tmp8, byte ptr ow0[edx]
	endif
	if oa1 eq atRegister
		movzx edx, byte ptr [ow1+edx]
		bswap edx
		mov dl, byte ptr [ow1+MbcmpO-1]
	else
		movzx edx, byte ptr ow1[edx]
		bswap edx
		mov dl, byte ptr ow1[MbcmpO-1]
	endif
	bswap edx
	cmp tmp32, edx
	pop tmp32
  endif
  if oqDeb
	oqCt=oqCt+1
	tmp8 CATSTR <oqE>, %oqCt	; end
	tmp32 CATSTR <oqL>, %oqCt	; less
	pushfd
	jl tmp32
	.if !Zero?
		PrintLine "&ow0", " Greater &ow1"
	.else
		PrintLine "&ow0", " Equals &ow1"
	.endif
	jmp tmp8
	tmp32:
		PrintLine "&ow0", " Lesser &ow1"
	tmp8:
	popfd
  endif
ENDM

Fsign MACRO rval
  ifb <rval>
    fst real4 ptr [esp-4]			;; real4 is enough, even for small negative numbers
    test byte ptr [esp-4+3], 80h		;; usage for sign of ST0: .if Fsign()
  else
    test byte ptr [rval-1+sizeof rval], 80h		;; usage:  .if Fsign(MyRealVar)
  endif
  EXITM <Sign?>
ENDM

FcmpGreater equ !Sign?	; ok for JWasm, 6.15, 9.0
FcmpLess equ Sign?
Fcmp MACRO cmp1:REQ, cmp2, prec	; -------- float comparison, sets zero and carry flag -----
LOCAL oa, prec1, is
  prec1=18			; default precision is medium, ca. REAL4
  ffree st(7)
  ifb <cmp2>
	fldz		; no second arg; compare against zero
  else
	ifnb <prec>
		prec1 INSTR <thml>, @SubStr(<prec>, 1, 1)
		if prec1		; predefined classes
			if prec1 eq 1
				prec1=63	; top, 19.5=REAL10, 19=59
			elseif prec1 eq 2
				prec1=45	; high, 15=REAL8, 44...46
			elseif prec1 eq 3
				prec1=18	; medium, 7=REAL4 p=17...19
			else
				prec1=8+1	; low, 4 digits, 0.1%, 8...9
			endif
		else		; roughly # of digits; REAL4=ca. 7
			prec1=3*prec	; 19+ top
			if prec ge 17	; 18=h
				prec1=prec1+7	; 15=m
			elseif prec le 12
				prec1=prec1-3
			endif	; 10=l
			if prec1 gt 63
				prec1=64
			endif
		endif
	endif
	FpuPush cmp2
  endif
  ffree st(7)
  FpuPush cmp1
  push prec1
  call MbFloatCmp
ENDM

IsTrue MACRO args, prec:=<medium>
LOCAL arg1, arg2, isEq, isNe, isLt, IsGt, isLe, isGe, is
  isEq INSTR <args>, < eq >
  isNe INSTR <args>, < ne >
  isLt INSTR <args>, < lt >
  isGt INSTR <args>, < gt >
  isLe INSTR <args>, < le >
  isGe INSTR <args>, < ge >
  is = isEq or isNe or isLt or isGt or isLe or isGe
  ife is
	tmp$ CATSTR <## line >, %@Line, <: allowed eq, ne, lt, gt, le, ge ##>
	.err tmp$
  endif
  if isGt or isLe	; swap for single jmp test
	arg2 SUBSTR <args>, 1, is-1
	arg1 SUBSTR <args>, is+4
  else
	arg1 SUBSTR <args>, 1, is-1
	arg2 SUBSTR <args>, is+4
  endif
  Fcmp arg1, arg2, prec
  if isEq
	EXITM <Zero?>
  elseif isNe
	EXITM <!Zero?>
  elseif isLt or isGt
	EXITM <Sign?>
  elseif isLe or isGe
	EXITM <!Sign?>
  endif
ENDM

FpuSet MACRO hiByte:=<0>, exFlags	; e.g. FpuSet MbNear64, exall; no args=set previous
  push ecx
  ifb <exFlags>
	push hiByte
  elseifidni <exall>, <exFlags>	; 0: invop, divzero, denorm, numover, numunder, but precision=1
	push hiByte+100000y*100h+10000h
  else
	push hiByte+exFlags*100h+10000h
  endif
  MbFpuStatusP PROTO
  call MbFpuStatusP
  pop ecx
ENDM

;	bits		54321098
MbNear64 =	10000011b
MbNear53 =	10000010b
MbNear24 =	10000000b
MbDown64 =	10000111b
MbDown53 =	10000110b
MbDown24 =	10000100b
MbUp64 =  	10001011b
MbUp53 =  	10001010b
MbUp24 =  	10001000b
MbTrunc64 =	10001111b
MbTrunc53 =	10001110b
MbTrunc24 =	10001100b

FpuFill MACRO regs:=<8>	; FpuFill 3
  push 1000+regs
  REPEAT regs
	ffree st(7)
	fild stack
	dec stack
  ENDM
  add esp, 4
ENDM	

FpuPush MACRO arg1
LOCAL oa, arg, dot, locR4
  if ChkNum(arg1) eq MbXmmR	; may trash eax
	arg SUBSTR <arg1>, 3
  else
	arg equ <arg1>
  endif
  oa = (opattr arg) AND 127
  if oa eq atImmediate
	push arg
	fild stack		; immediate integer or reg32 on stack, then on FPU
	add esp, 4
  elseif NumSize eq MbXmmI	; xmm integer
	sub esp, QWORD
	movlps qword ptr [esp], arg
	fild QWORD ptr [esp] 
	add esp, QWORD
  elseif NumSize eq MbXmmR	; f:xmm real
	sub esp, QWORD
	movlps qword ptr [esp], arg
	fld QWORD ptr [esp] 
	add esp, QWORD
  elseif oa eq atRegister
	push arg		; attention reg32 always signed!
	fild stack		; immediate integer or reg32 on stack, then on FPU
	pop arg			; restore register
  elseif NumSize eq MbQword	; qword in mem
	fild arg1
  elseif NumSize eq MbDword	; dword in mem
	if TYPE(arg1) eq TBYTE
		fld arg1
	else
		fild arg1
	endif
  else
	oa INSTR arg, <]>	; some structure?
	dot INSTR <arg1>, <.>	; immediate real
	if dot gt oa
		.DATA
			locR4 REAL4 arg1
		.CODE
			fld locR4
	elseifidn aPass$, <eax>
		if NumSize eq MbReal8
			fld REAL8 ptr [eax]
		elseif NumSize eq MbReal10
			fld REAL10 ptr [eax]
		else
			fld arg
		endif
	else
		fld arg		; real on FPU, any other size
	endif
  endif
ENDM

FpuSave MACRO numregs:=<2>
LOCAL ct
  FpuSaveRegs=numregs
  FpuSaveSize=16
  sub esp, FpuSaveSize*FpuSaveRegs
  ct=0
  REPEAT FpuSaveRegs
	@CatStr(<fxch st(>, %(7-ct), <)>)
	fstp REAL10 ptr [esp+ct*FpuSaveSize]
	@CatStr(<fld st(>, %(6-ct), <)>)
	@CatStr(<ffree st(>, %(7-ct), <)>)
	ct=ct+1
  ENDM
  nop
ENDM
FpuRestore MACRO
LOCAL ct
  ct=0
  REPEAT FpuSaveRegs
	fld REAL10 ptr [esp+ct*FpuSaveSize]
	ct=ct+1
  ENDM
  REPEAT FpuSaveRegs
	fincstp
  ENDM
  add esp, FpuSaveSize*FpuSaveRegs
ENDM
Flags MACRO pos			; for more than 32 flags see here
  bt MbFlags, pos
  LastFlag equ <pos>
  EXITM <CarrY?>
ENDM

SetFlags MACRO pos, mode
  .if mode
	bts MbFlags, pos
  .else
	btr MbFlags, pos
  .endif
ENDM
LineCount MACRO src, nBytes:=<-1>, CrLfChar:=<cr>
  ifidni <CrLfChar>, <cr>
	push 0d0d0d0dh
  elseifidni <CrLfChar>, <lf>
	push 0a0a0a0ah
  else
	push CrLfChar+100h*CrLfChar+10000h*CrLfChar+1000000h*CrLfChar
  endif
  ifidn <nBytes>, <-1>
	push Len(src)
  else
	push nBytes
  endif
  push src
  LineCountP PROTO
  call LineCountP
  EXITM <eax>
ENDM
PopCount MACRO pcSource, pcDest
Local is16, tmp$
  EXTERNDEF pcTable:DWORD
  if @InStr(1, <pcSource>, <8:>)
	tmp$ SUBSTR <pcSource>, 3
	ifdifi tmp$, <eax>
		if (opattr tmp$) eq atRegister
			movzx eax, byte ptr pcTable[tmp$]
		else
			mov eax, tmp$
			movzx eax, byte ptr pcTable[eax]
		endif
	else
		movzx eax, byte ptr pcTable[eax]
	endif
  elseif @InStr(1, <pcSource>, <16:>)
	mov edx, @SubStr(<pcSource>, 4)
	movzx eax, dh
	movzx eax, byte ptr pcTable[eax]
	movzx edx, dl
	movzx edx, byte ptr pcTable[edx]
	add eax, edx
  else
	push ecx
	push ebx
	mov ebx, pcSource
	movzx ecx, bh
	movzx eax, byte ptr pcTable[ecx]
	movzx ecx, bl
	movzx edx, byte ptr pcTable[ecx]
	bswap ebx
	movzx ecx, bh
	add eax, edx
	movzx edx, byte ptr pcTable[ecx]
	add eax, edx
	movzx ecx, bl
	movzx edx, byte ptr pcTable[ecx]
	add eax, edx
	pop ebx
	pop ecx
  endif
  ifb <pcDest>
	EXITM <eax>
  else
	ifdifi <dest>, <eax>
		mov pcDest, eax
	endif
	EXITM <>
  endif
ENDM

pcRetReal = 0	; default: return integer in eax
FpuPercent MACRO args:VARARG
  pcRetReal = 99
  EXITM Percent(args)
ENDM
fpuPercent MACRO args:VARARG
  pcRetReal = 99
  EXITM Percent(args)
ENDM
f4Percent MACRO args:VARARG
  pcRetReal = 4
  EXITM Percent(args)
ENDM
f8Percent MACRO args:VARARG
  pcRetReal = 8
  EXITM Percent(args)
ENDM
Percent MACRO source:REQ, percent:REQ, fail
LOCAL oas, oap, oad, dot, pcNewReals, pcNewRealp, argPushed
  ifnb <fail>
	% echo @CatStr(<## Percent: too many args in line >, %@Line, < ##>)
	.err
  endif
  ifndef pcZeroOne
    .DATA
	pcZeroOne REAL10 0.01	; full precision
    .DATA?
	pcRet8 REAL8 ?	; 8 bytes for returns to Str$ etc
	pcRet4 REAL4 ?	; 4 bytes for returns to Str$ etc
    .CODE
  endif
  oas = 0
  argPushed = 0
  dot INSTR <source>, <.>
  ife dot
	oas = (opattr source) AND 127
  endif
  oap = 0
  dot INSTR <percent>, <.>
  ife dot
	oap = (opattr percent) AND 127
  endif
  ffree st(7)
  if (oas eq atRegister) or (oas eq atImmediate)
	push source
	argPushed = 1
	fild stack
  elseife oas
	dot INSTR <source>, <.>
	ife dot
			.err @CatStr(<## Invalid Percent source in line >, %@Line, < ##>)
	endif
  .DATA
  	if @SizeStr(<source>) gt 9
		@CatStr(<pcNewReals REAL8 >, <source>)
	else
		@CatStr(<pcNewReals REAL4 >, <source>)
	endif
  .CODE
	fld pcNewReals
  elseif (type(source) eq REAL4) or (type(source) eq REAL8) or (type(source) eq REAL10)
	fld source
  else
	fild source
  endif
  if (oap eq atRegister) or (oap eq atImmediate)
	if argPushed
		mov stack, percent	; reg32 or immediate: move into stack slot
	else
		push percent
		argPushed = 1
	endif
	fimul stack
  elseife oap
	dot INSTR <percent>, <.>
	ife dot
			.err @CatStr(<## Invalid percentage in line >, %@Line, < ##>)
	endif
  .DATA
  	if @SizeStr(<percent>) gt 9
		@CatStr(<pcNewRealp REAL8 >, <percent>)
	else
		@CatStr(<pcNewRealp REAL4 >, <percent>)
	endif
  .CODE
	fmul pcNewRealp
  elseif type(percent) eq REAL10
	ffree st(7)
	fld percent
	fmul	;; pops ST
  elseif (type(percent) eq REAL4) or (type(percent) eq REAL8)
	fmul percent	; multiply 1% by required percentage
  else
	fimul percent	; multiply 1% by required percentage
  endif
  fld pcZeroOne
  fmul 			; multiply with 0.01, i.e. divide source by 100
  if pcRetReal
	if pcRetReal eq 4
		fstp pcRet4	; store result in Real4
		pcRetReal = 0	; restore default
		if argPushed
		   pop eax	; correct stack if necessary
		endif
		EXITM <pcRet4>
	elseif pcRetReal eq 8
		fstp pcRet8	; store result in Real8
		pcRetReal = 0	; restore default
		if argPushed
		   pop eax	; correct stack if necessary
		endif
		EXITM <pcRet8>
	else
		pcRetReal = 0	; restore default
		if argPushed
		   pop eax	; correct stack if necessary
		endif
		EXITM <ST(0)>	; fpuPercent return, usable e.g. by Str$()
	endif
  else
	ife argPushed
		push eax	; create dword slot
	endif
	fistp stack	; store result on stack
	pop eax	; return integer in eax
	EXITM <eax>
  endif
ENDM

MbExp PROTO
ExpXY MACRO argX, argY, dest	; credits to qWord and Agner Fog
  ffree st(7)
  FpuPush argY	; fld argY
  ffree st(7)
  FpuPush argX	; fld argX
  fyl2x
  call MbExp
  ifb <dest>
	EXITM <ST(0)>
  else
	fstp dest
	EXITM <>
  endif
ENDM

Exp2 MACRO arg, dest
  ffree st(7)
  FpuPush arg
  call MbExp
  ifb <dest>
	EXITM <ST(0)>
  else
	fstp dest
	EXITM <>
  endif
ENDM

Exp10 MACRO arg, dest
  ffree st(7)
  FpuPush arg
  call MbExp[-6]
  ifb <dest>
	EXITM <ST(0)>
  else
	fstp dest
	EXITM <>
  endif
ENDM

ExpE MACRO arg, dest
  ffree st(7)
  FpuPush arg
  call MbExp[-12]
  ifb <dest>
	EXITM <ST(0)>
  else
	fstp dest
	EXITM <>
  endif
ENDM

Bsr64 MACRO argQ
Local c3$
  ifnb <argQ>
	c3$ CATSTR <argQ>, <   >
	c3$ SUBSTR c3$, 1, 3
	ifidni c3$, <xmm>
		push edx
		push eax
		movlps oword ptr [esp], argQ
		pop eax
		pop edx
	else
		mov eax, dword ptr argQ
		mov edx, dword ptr argQ[4]
	endif
  endif
  push eax
  bsr eax, edx		; non-zero if edx is non-zero
  pop edx
  .if Zero?
	bsr eax, edx
  .else
	add eax, 32
  .endif
  exitm <eax>
ENDM

MbRdq=0
Rand64 MACRO args
  MbRdq=1
  ifnb <args>
	.err @CatStr(<## line >, %@Line, <: no arguments allowed ##>)
  endif
  EXITM Rand(-1)
ENDM
Rand MACRO rgLow, rgHigh, randDest	; to reg32, byte, word, dword, qword, r4, r8, r10, xmm, f:xmm
LOCAL oa, rgLowD, rgHighD, dot, tmp$, LeaRD, destType
  ifndef MbRndSeed
	.DATA
	align 16			; needs an align 16 to be fast
	MbRndSeed dd "Ciao"
	.CODE
  endif
  ifb <rgLow>
	MbRs PROTO
	call MbRs	; Rand(): initialise
	mov MbRndSeed, eax
	EXITM <>
  else
	oa INSTR <rgLow>, <:>	; Rand(seed:ciao)
	if oa eq 5
		tmp$ SUBSTR <rgLow>, 6
		tmp$ CATSTR <mov MbRndSeed, ">, tmp$, <">
		tmp$
		EXITM <>
	endif
  endif
  destType=99			; default
  ifnb <randDest>		; mov MyDwordArray(ecx), Rand(123) uses edx
	destType=ChkNum(randDest)	; ChkNum returns aPass$, may have ?p:
	tmp$ CATSTR <randDest>	; looks horribly complicated
	LeaRD INSTR tmp$, <[>	; but JWasm needs it
	if LeaRD
		lea edx, randDest
		push edx
	endif
  endif
  mov eax, MbRndSeed	; Initial value
  imul eax, eax, -127	; randomise (imul eax, MbRndSeed, -127 is slow)
  add eax, -124	; the magic
  bswap eax		; we need the high order bits
  mov MbRndSeed, eax	; save for next round
  ifb <rgHigh>				; Rand(123): return dword; only integers allowed
	ife MbRdq
		push edx	; mov MyDwordArray(99), Rand(123) uses edx, so we better save it
	endif
	oa = (opattr rgLow) AND 127
	if oa eq 36
		if rgLow ge -128 and rgLow le 127
			if rgLow eq -1
				or edx, -1
			else
				push rgLow
				pop edx
			endif
		else
				mov edx, rgLow	; multiply MbRndSeed
		endif
		mul edx 	; with rgLow
	else
		mul rgLow	; multiply MbRndSeed with rgLow
	endif
	xchg eax, edx
	ife MbRdq
		pop edx
	endif
	MbRdq=0
	EXITM <eax>	; return random number, leave edx intact for arrays
  endif
  dot INSTR <rgHigh>, <.>
  if dot
	.DATA
	  rgHighD REAL8 rgHigh
	.CODE
	fld rgHighD
  else
	if (opattr rgHigh) eq 36	; immediate integer
			ifidn <rgHigh>, <1>
				fld1
			else
				push rgHigh
				fild stack
				pop edx
			endif
	elseif TYPE(rgHigh) eq DWORD	; global or local dword
			if (opattr rgHigh) eq 48	; register
				push rgHigh
				fild stack
				pop rgHigh
			else
				fild rgHigh
			endif
	else
		fld rgHigh	; REAL var
	endif
  endif
  dot INSTR <rgLow>, <.>
  if dot
	.DATA
	  rgLowD REAL8 rgLow
	.CODE
	fld rgLowD
	fld st
	fsubp st(2), st
	fxch
  elseifdif <rgLow>, <0>
	if (opattr rgLow) eq 36	; immediate integer
			ifidn <rgLow>, <1>
				fld1
			else
				push rgLow
				fild stack
				pop edx
		endif
	elseif TYPE(rgLow) eq DWORD	; global or local dword
			if (opattr rgLow) eq 48	; register
				push rgLow
				fild stack
				pop edx	; correct the stack
			else
				fild rgLow
			endif
	else
		fld rgLow	; REAL var
	endif
	fld st
	fsubp st(2), st
	fxch
  endif
  push 0			; high dword
  or edx, -1		; maybe a simple push eax
  mul edx			; would be enough...?
  push edx		; low dword
  fild qword ptr [esp]
  fmul			; pops ST
  ifndef MbRndMul
	.DATA
	MbRndMul REAL8 2.3283064365387E-010
	.CODE
  endif
  fmul MbRndMul	; no pop
  ifdif <rgLow>, <0>
	fadd	; pops ST
  endif
  ifb <randDest>
	pop edx	; restore correct
	pop edx	; stack count
	EXITM <>	; result in ST
  endif
  if LeaRD		; SIZE ptr [edx]: DWORD includes BYTE and WORD
	if destType eq MbDword or destType eq MbQword
		mov edx, [esp+8]	; get randDest
		fnstcw word ptr [esp]	; save original
		fnstcw word ptr [esp+2]	; plus a copy
		mov byte ptr [esp+1], 0111b	; MbDown64
		fldcw word ptr [esp]	; set new control word
		oa INSTR aPass$, <p:>
		if oa eq 2
			tmp$ SUBSTR aPass$, 1, 3
			ifidni tmp$, <wp:>
				fistp word ptr [edx]
			else
				fistp word ptr [esp]
				mov al, [esp]
				mov [edx], al
			endif
		elseif destType eq MbDword
			fistp dword ptr [edx]
		else
			fistp qword ptr [edx]
		endif
		fldcw word ptr [esp+2]	; set old control word
		pop edx	; restore correct
		pop edx	; stack count
		pop edx	; pushed randDest
	else
		pop edx	; restore correct
		pop edx	; stack count
		pop edx	; pushed randDest
		if destType eq MbReal4
			fstp REAL4 ptr [edx]	; must come after the pops
		elseif destType eq MbReal8
			fstp REAL8 ptr [edx]
		elseif destType eq MbReal10
			fstp REAL10 ptr [edx]
		endif
	endif
  elseif destType eq MbXmmR
	fstp REAL8 ptr [esp]
	tmp$ SUBSTR <randDest>, 3
	movq tmp$, REAL8 ptr [esp]	; movq xmm0, ...
	pop edx			; restore correct
	pop edx			; stack count
  elseif destType eq MbXmmI
	fstp REAL8 ptr [esp]
	movq randDest, qword ptr [esp]
	cvttpd2dq randDest, randDest	; convert with truncation
	pop edx			; restore correct
	pop edx			; stack count
  else
	if destType eq MbDword or destType eq MbQword	; xmm or mem real8
		fnstcw word ptr [esp]	; save original
		fnstcw word ptr [esp+2]	; save a copy
		mov byte ptr [esp+1], 0111b	; MbDown64
		fldcw word ptr [esp]	; set new control word
		fistp randDest
		fldcw word ptr [esp+2]	; set old control word
	else
		fstp randDest
	endif
	pop edx			; restore correct
	pop edx			; stack count
  endif
ENDM				; ---------- end Rand() ----------

mpx equ <[edi.MbPipe]>
mphRes1	equ <dword ptr [edi-MbPipe-28]>	; see lsp
mphExitCode$	equ <dword ptr [edi-MbPipe-24]>	; unused
mphExitCode	equ <dword ptr [edi-MbPipe-20]>
mphBufferStart	equ <dword ptr [edi-MbPipe-16]>	; relative to edi(slot 1), i.e. Launch$ only
mphBufferEnd	equ <dword ptr [edi-MbPipe-12]>	; ditto
mphTimeout	equ <dword ptr lsp[-8]>		; used as global var, Launch$ only
mphCurPipe	equ <dword ptr lsp[-4]>		; SetPipe

SwPipeFlag=-99	; Launch pipe if set
MbTimeout=5000			; five seconds for Launch$()
lspExitC$ 	equ <dword ptr lsp[-6*4]>
lspExitC 	equ <dword ptr lsp[-5*4]>
ExitCode MACRO arg	; ec(), ec($), ec(#slot)
  ifb <arg>
	mov edx, lspExitC	; non-cb Launch
  elseif @InStr(1, <arg>, <$>)
	mov edx, lspExitC$	; Launch$
  else
	push ecx	; save ecx
	push INVALID_HANDLE_VALUE	; set slot to IHV if gecp fails
	push esp	; lpExitCode
	push LaunchHandle(arg)
	call GetExitCodeProcess
	pop edx
	pop ecx
  endif
  EXITM <edx>
ENDM
SetLaunchTimeout MACRO arg
  ExternDef MbLaMs:DWORD
  mov MbLaMs[4], arg
ENDM
LaunchID macro arg1
LOCAL arg
  arg=999
  ifb <arg1>
	arg=-2
  elseifidn <arg1>, <$>
	arg=-1
  elseifidni <arg1>, <cb>
	arg=0
  elseif (opattr arg1) eq atImmediate
	arg=arg1
  endif
  if arg lt 999
	mov eax, dword ptr lsp[arg*MbPipe+MbPipe.mphID+2*MbPipe]
  else
	imul eax, arg1, dword ptr MbPipe
	mov eax, dword ptr lsp[eax+MbPipe.mphID+2*MbPipe]
  endif
  EXITM <eax>
ENDM
LaunchHandle macro arg1
LOCAL arg
  arg=999
  ifb <arg1>
	arg=-2
  elseifidn <arg1>, <$>
	arg=-1
  elseifidni <arg1>, <cb>
	arg=0
  elseif (opattr arg1) eq atImmediate
	arg=arg1
  endif
  if arg lt 999
	EXITM <dword ptr lsp[arg*MbPipe+MbPipe.mphProcess+2*MbPipe]>
  endif
  imul eax, arg1, MbPipe
  EXITM <dword ptr lsp[eax+MbPipe.mphProcess+2*MbPipe]>
ENDM

SetPipe MACRO arg:=<0>
  push arg
  pop mphCurPipe
ENDM  

LaunchEndPos MACRO
  imul edx, mphCurPipe, MbPipe
  EXITM <lsp.mphPosEdit[edx+2*MbPipe]>
ENDM

SwPipeFlag=-99
WritePipe MACRO arg, wpCrLf:=<1>
  push repargA(arg)
  push wpCrLf
  WriteData PROTO: DWORD, :DWORD
  call WriteData
ENDM

Launch$ MACRO LxCmd:REQ, LxShowSW:=<SW_MINIMIZE>, LxTimeout:=<esp>, LxFlags
  if (opattr LxTimeout) eq atImmediate	; no slots for Launch$
	if LxTimeout le 0
		.err <timeout must be positive>
	else
		@CatStr(<push >, %LxTimeout)
	endif
  elseifdif <LxTimeout>, <esp>
	push LxTimeout
  else
	push MbTimeout
  endif
  pop dword ptr lsp[-8]		; aka mphTimeout
  Launch LxCmd, LxShowSW, SwPipeFlag, LxFlags		; push -99, short
  EXITM emArr$
ENDM
debErr2Con macro errmax:=<1>
Local tmp$
  if usedeb
	ifidni SubSys, <console>
		.if eax<errmax
			tmp$ CATSTR <"Error in line >, %@Line, <:">
			deb 4, tmp$, eax, $Err$()
		.endif
	endif
  endif
ENDM

ShEx MACRO pDoc, sMode:=<SW_RESTORE>
  push ecx
  invoke ShellExecute, 0, 0, repargA(pDoc), 0, 0, sMode
  debErr2Con 33
  pop ecx
ENDM
wShEx MACRO pDoc, sMode:=<SW_RESTORE>
  push ecx
  invoke ShellExecuteW, 0, 0, repargW(pDoc), 0, 0, sMode
  debErr2Con 33
  pop ecx
ENDM
uShEx MACRO pDoc, sMode:=<SW_RESTORE>
  push ecx
  invoke ShellExecuteW, 0, 0, uChr$(repargW(pDoc)), 0, 0, sMode
  debErr2Con 33
  pop ecx
ENDM
MbShell equ <ShellWait>
Launch MACRO LaCmd:REQ, LaShowSW:=<SW_NORMAL>, LaTimeout:=<0>, LaFlags:=<0>
LOCAL ShowMode, is, is2, cbSlot
  MbShell PROTO:DWORD, :DWORD, :DWORD, :DWORD
  ShowMode equ <LaShowSW>
  ifidn ShowMode, <SW_HIDE>
	ShowMode equ <SW_HIDE or 65536>
  elseifidni ShowMode, <passdata>
	ifidn <LaFlags>, <0>
		push repargA(LaTimeout)	; the pointer
		push [esp]
		is INSTR <LaTimeout>, <OffSet>	; wChr$
		ife is
			is INSTR <LaTimeout>, <( EdX)>	; wRes$
		endif
		if is
			call MbStrLenW
			add eax, eax	; we need bytes
		else
			call MbStrLen
		endif
		xchg eax, [esp]
		push eax
	else
		push LaFlags
		push repargA(LaTimeout)	; the pointer
	endif
	push 127		; flag "we pass data"		
	push repargA(LaCmd)
	call ShellWait
	EXITM
  endif
  is INSTR <LaTimeout>, <cb:>
  if is
	is2 INSTR is+3, <LaTimeout>, <:>	; e.g. cb:hEdit:ecx
	if is2
		push @SubStr(<LaTimeout>, is+3, is2-is-3)
		cbSlot SUBSTR <LaTimeout>, is2+1
		if (opattr cbSlot) eq atImmediate
			pop lsp.mphEdit[MbPipe*(cbSlot+2)]
			cbSlot CATSTR %(SwPipeFlag+10000h*(cbSlot+1))
		else
			ifdifi cbSlot, <edx>
				mov edx, cbSlot
			endif
			inc edx
			shl edx, 5	; mul MbPipe
			pop lsp.mphEdit[edx+MbPipe]	; cbSlot+2
			shl edx, 11
			add edx, SwPipeFlag
			cbSlot equ <edx>
		endif
	else
		push @SubStr(<LaTimeout>, is+3)	; the handle
		cbSlot=SwPipeFlag+10000h	; cb launch, no slot set: push 0+1, pop 0+2
		pop lsp.mphEdit[2*MbPipe]
	endif
	invoke MbShell, repargA(LaCmd), ShowMode, cbSlot, LaFlags	; callback has fixed timeout zero, so we can use SwPipeFlag
  else
	invoke MbShell, repargA(LaCmd), ShowMode, LaTimeout, LaFlags
  endif
ENDM

AddWin$ MACRO pTxt, iStart, iEnd
LOCAL is, hEd, str2Add
  is INSTR <pTxt>, <=>
  hEd SUBSTR <pTxt>, 1, is-1
  str2Add SUBSTR <pTxt>, is+1
  push Cat$(str2Add)
  push 0
  push EM_REPLACESEL
  push hEd 		; [esp+12]
  ifnb <iStart>
	ifb <iEnd>
		push iStart
	else
		push iEnd
	endif
	push iStart
  else
	invoke GetWindowTextLength, hEd
	push eax
	push eax
  endif
  push EM_SETSEL
  push [esp+12]
  call SendMessage
  call SendMessage
ENDM
wAddWin$ MACRO pTxt, iStart, iEnd
LOCAL is, hEd, str2Add
  is INSTR <pTxt>, <=>
  hEd SUBSTR <pTxt>, 1, is-1
  str2Add SUBSTR <pTxt>, is+1
  is INSTR str2Add, <">
  if is
	push uChr$(str2Add)
  else
	push repargW(str2Add)
  endif
  push 0
  push EM_REPLACESEL
  push hEd
  ifnb <iStart>
	ifb <iEnd>
		push iStart
	else
		push iEnd
	endif
	push iStart
  else
	invoke GetWindowTextLength, hEd
	push eax
	push eax
  endif
  push EM_SETSEL
  push [esp+12]
  call SendMessage
  call SendMessageW
ENDM
ParentData$ MACRO dummyarg
  if MbUseErrLine
	mov MbErrLine, @Line
  endif
  MbPDat PROTO
  call MbPDat
  EXITM <eax>
ENDM

MouseX	equ <MouseMacX()>
MouseY	equ <MouseMacY()>
MouseK	equ <MouseMacK()>

MouseMacX MACRO
  push ecx
  invoke GetCursorPos, offset MousePos
  pop ecx
  EXITM <MousePos.x>
ENDM

MouseMacY MACRO
  push ecx
  invoke GetCursorPos, offset MousePos
  pop ecx
  EXITM <MousePos.y>
ENDM

MouseMacK MACRO	; MouseK
  MouseKeys PROTO
  call MouseKeys
  EXITM <eax>
ENDM

crtbuf MACRO var, BufLen, msAlign:=<4>	; cb pBuffer, 1000 [, 16]
LOCAL cblabel
.DATA?
align msAlign
  cblabel LABEL BYTE
  var equ offset cblabel
  ORG $+BufLen-1
  db ?
.CODE
ENDM

CRT MACRO croutine, args0:VARARG
LOCAL args, buf$
  buf$ equ <>
  args CATSTR <invoke crt_>, <croutine>
  for arg, <args0>
	; % echo [arg]
	ifidni <arg>, <buffer>
		buf$ equ <arg>
		args CATSTR args, <, edi>
	else
		args CATSTR args, <, >, reparg(arg)
	endif
  ENDM
  ifnb buf$
	push edi
	invoke MbBufferGet
	xchg eax, edi
	args
	push 1
	add Len(edi), edi
	push eax
	call MbBufferFix
	pop edi
	args SUBSTR args, 14
	if usedeb
		% echo invoke args
	endif
	Exitm emArr$
  else
	args
	Exitm <eax>
  endif
ENDM

ifndef SafeCopy
SafeCopy MACRO dest, arr$, maxbytes
  ifdif <arr$>, emArr$
	.err @CatStr(<## line >, %@Line, <: source must be string array element ##>)
  elseifidn <dest>, emArr$
	.err @CatStr(<## line >, %@Line, <: desf cannot be a string array element ##>)
  elseifidni <dest>, <eax>
	.err @CatStr(<## line >, %@Line, <: desf cannot be eax ##>)
  else
	test edx, edx
	.if Sign?
		neg edx
	.elseif Zero?
		if @InStr(1, <dest>, <addr>)
			lea edx, @SubStr(<dest>, 5)
			and dword ptr [edx], 0
			xor edx, edx
		elseif @InStr(1, <dest>, <[e>)
			lea edx, dest
			and dword ptr [edx], 0
			xor edx, edx
		elseif (opattr dest) eq atRegister
			and byte ptr [dest], 0
		endif
	.endif
	.if edx>maxbytes
		deb 9, "## SafeCopy: ##", edx	;; depends on usedeb
		if (opattr maxbytes) eq atImmediate
			if maxbytes LE 127
				m2m edx, maxbytes
			else
				mov edx, maxbytes
			endif
		elseifdifi <maxbytes>, <edx>
			mov edx, maxbytes
		endif
	.endif
	invoke MbCopy, dest, eax, edx
  endif
ENDM
endif

; BMOVE ab_adr%, an_adr% [, anz%]
Bmove MACRO src:REQ, dest:REQ, ct:=<-1>
  push ct
  push repargA(src)
  push dest
  call MbCopy	; invoke MbCopy, dest, src, ct
ENDM

DefNumDigits=7
DefNumSet=0
DefNum MACRO precision	; 1...19
LOCAL digits
	digits = 7				; default
	ifnb <precision>
		digits = 19				; -1, 0, 20+
		DefNumSet=1
		if precision GT 0
			if precision LE 19
				digits = precision	; DefNum 19 is OK with REAL10
			endif
		endif
	endif
	DefNumDigits=digits
	push digits
	pop MbDefNum
ENDM

wCount MACRO args:VARARG
  ucInstr=32+128
  EXITM Instr_(args)
ENDM
Count MACRO args:VARARG
  ucInstr=32
  EXITM Instr_(args)
ENDM
wInstr MACRO args:VARARG
  ucInstr=128
  EXITM Instr_(args)
ENDM 
wInstr_ MACRO args:VARARG
  ucInstr=128
  EXITM Instr_(args)
ENDM
InstrOr MACRO src, pat0, mode	; .if InstrOr(file, ".txt" or ".inc" or ".rc", 1)
LOCAL tmp$, is, pat$, p1$, ct, px$
  pat$ CATSTR <pat0>, < or xx>
  is INSTR pat$, < or >
  push ebp
  mov ebp, esp
  WHILE is
  	LOCAL lbl
	p1$ SUBSTR pat$, 1, is-1
	lbl CATSTR <lbl>, %is
	.DATA
	lbl db p1$, 0
	.CODE
	push offset lbl
	pat$ SUBSTR pat$, is+4
	is INSTR pat$, < or >
  ENDM
  .Repeat
	pop eax
	.Break .if Instr_(1, src, eax, mode)
  .Until esp>=ebp
  leave
  EXITM <!Zero?>
ENDM
ucInstr=0
; A: has startpos:	INSTR(curpos, "Test", "Te", 2)	; 4 args
; A: has startpos:	INSTR(curpos, "Test", "Te", FAST)	; 4 args, ultrafast mode
; B: no startpos:	INSTR("Test", "Te", 2)	; 3 args, last one immediate
; C: has startpos:	INSTR(curpos, "Test", "Te")	; 3 args, last one not immediate
; D: no startpos:	INSTR("Test", "Te")		; 2 args, or 3 and last one immediate
Instr_ MACRO sPos, Src$, Sub$, sMode
LOCAL last_imm, sm1$
  ifnb <sMode>
	ife ucInstr
		ifidni <sPos>, <fast>
			if @InStr(1, <02x64x66>, %sMode)
				ifidn <Src$>, emArr$
				    push sMode or 64
				else
				    push sMode
				endif
				push repargA(Sub$)
				push repargA(Src$)
				InsJb PROTO :DWORD, :DWORD, :DWORD
				call InsJb
				EXITM <edx>
			else
				tmp$ CATSTR <## line >, %@Line, <: fast Instr_() allows only modes 0 and 2 ##>
				% echo tmp$
				.err
			endif
		endif
	endif
	push sMode+ucInstr	;; A: 4 args, easiest case
	PushString Sub$
	PushString Src$
	push sPos
  elseifnb <Sub$>
  	sm1$ SUBSTR <Sub$>, 1, 1
	last_imm INSTR <0123456789>, sm1$
	if last_imm
		push Sub$+ucInstr	;; B: 3 args, last one immediate, so sPos=Src, Src=Sub
		PushString Src$	;; Sub$
		PushString sPos	;; Src$
		push 1	;; added: default startpos
	else
		push ucInstr	;; C: 3 args, last one not immediate, so it has sPos, added: default mode
		PushString Sub$
		PushString Src$
		push sPos
	endif
  else
	push ucInstr	;; D: 2 args, added: default mode
	PushString Src$	;; Sub$
	PushString sPos	;; Src$
	push 1	;; added: default startpos
  endif
  ucInstr=0		;; restore mode
  call InstrCi		;; invoke InstrCi, sPos, repargA(Src$), repargA(Sub$), sMode
  EXITM <edx>	;; relative pos in edx, absolute in eax
ENDM

wRinstr MACRO Src$, Sub$
  push esi
  mov esi, repargW(Src$)
  push esi
  call MbStrLenW
  mov dl, Sub$	; Sub$ must be single byte, e.g. "\"
  inc eax 
  .Repeat
	dec eax
	.Break .if Sign?
  .Until [esi+2*eax]==dl
  .if Zero?
	inc eax
  .endif
  mov edx, eax
  lea eax, [esi+2*eax]
  pop esi
  EXITM <edx>
ENDM

Rinstr MACRO sPos, Src$, Sub$, sMode
LOCAL last_imm, sm1$
  ifnb <sMode>
	push sMode or 64	;; A: 4 args, easiest case
	PushString Sub$	;; NEW
	PushString Src$
	if (opattr sPos) eq 36	;; immediate startpos+2
		push sPos+2
	else
		push sPos
		add stack, 2	;; rare case, easier here than in InstrCi
	endif
  elseifnb <Sub$>
  	sm1$ SUBSTR <Sub$>, 1, 1
	last_imm INSTR <0123456789>, sm1$
	if last_imm
		push Sub$ or 64	;; B: 3 args, last one immediate, so sPos=Src, Src=Sub
		PushString Src$	;; Sub$
		PushString sPos	;; Src$
		push -1	;; added: default startpos rinstr, negative
	else
		push 64	;; C: 3 args, last one not immediate, so it has sPos, added: default mode
		PushString Sub$
		PushString Src$
			if (opattr sPos) eq 36
				push sPos+2
			else
				push sPos
				add stack, 2
			endif
	endif
  else
	push 64	;; D: 2 args, added: default mode
	PushString Src$	;; Sub$
	PushString sPos	;; Src$
	push -1	;; added: default startpos
  endif
  call InstrCi   	;; invoke InstrCi, sPos, repargA(Src$), repargA(Sub$), sMode
  EXITM <edx> 		;; relative pos in edx, absolute in eax
ENDM

; ---------- flags for Extract$ ---------
xsDefault=	0	; user may change this
xsExcL=	0	; exclude left pattern, e.g. {url= ... }
xsExcR=	0	; exclude right pattern
xsCaseI=	1	; case-insensitive
xsIs=	2	; intellisense; if patL starts with ?, any character will be accepted, useful for D:\Masm___.ext 
xsFullW=	4	; full word (left match only)
xsI1c=	8	; ignore 1st char in left match, e.g. ?:\Masm32\... 
xsIncL=	16	; include left pattern (e.g. http://)
xsIncR=	16*256	; include right pattern (4096)
xsTrimL=	32	; trim left side, i.e. strip everything <=ASCII 39 aka single quote
xsTrimR=	64	; trim right side (after excluding right match if xsExcL is set)
xsTrim=	xsTrimL or xsTrimR		; (96)
xsLineL=	128	; include line of the left match
xsLineR=	128*256	; include rest of line after the right match (must include right match...) (32768)
xsWildcard=	256	; allow <start*end> for left match
xsLoop=	512	; let Instr_ start behind the last position, for using in loops
xsEscape=	1024	; translate \n and \t to CrLf$ and Tb$
xsTrim39=	2048	; trim everything <=39
xsScan=	32*256 or xsExcR or xsExcL or xsLoop	; sequential scan for single delimiter (8192)
xsLoopLet=		0
Extract$ MACRO src:REQ, pl:REQ, pr:=<13>, mode1:=<xsDefault>, lines:=<1>, pos:=<1>
LOCAL is, mode, blankpos
  mode=mode1 and not xsEscape	; string to int
  if mode and xsLoop
	xsLoopLet=@Line
	if (mode and xsScan) eq xsScan
		ifdif <pl>, <pr>
			@CatStr(<echo ## line >, %@Line, <: with xsScan, left and right patterns must be identical ##>) 
			.err
		endif
	endif
	mode=mode and not xsLoop
	push 0
  else
	xsLoopLet=0
	push pos
  endif
  push lines
  if mode
	push mode
  else
	is INSTR <pl>, <?>
	if is eq 2	; e.g filename, "?:\ or '?:\
		push xsI1c or xsIncL or xsExcR or xsTrimR
	else
		push 0
	endif
  endif
  if @Imm(pr)
	ife pr
		push 13
	else
		if (mode1 eq xsDefault) and (pr le xsLineR)
			@CatStr(<echo ## line >, %@Line, <: check if you forgot the right match ##>) 
		endif
		push pr
	endif
  else
	push repargA(pr)
  endif
  push repargA(pl)
  push repargA(src)
  ExtractP PROTO :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
  call ExtractP
  if mode1 and xsEscape
	push eax
	.Repeat
		.Break .if !eax
		.if byte ptr [eax]=="\"
			mov dl, [eax+1]
			.if dl=="n"
				mov word ptr [eax], 13+10*256
			.elseif dl=="t"
				mov word ptr [eax], 32+9*256
			.endif
		.endif
		inc eax
	.Until !byte ptr [eax]
	pop eax
  endif
  EXITM emArr$	; make sure Let reads it properly
ENDM

mtxt equ MIRROR$
Mirror$ MACRO Src:REQ		;;usg: mirror text: cmp eax, Mirror$("Masm")
LOCAL hasQu, tmp$
  hasQu INSTR <Src>, <">
  ife hasQu
	hasQu INSTR <Src>, <'>
  endif
  if hasQu
	tmp$ equ <>
	FORC char, <Src>
		tmp$ CATSTR <char>, tmp$
	ENDM
	EXITM <tmp$>
  else
	push Src
	MbFlipP PROTO
	call MbFlipP
	EXITM emArr$	; make sure Let reads it properly
  endif
ENDM
MirrorBits MACRO arg32	; reverts bitwise, e.g. 0001011 -> 1101000
  ifdifi <arg32>, <eax>
	mov eax, arg32
  endif
  mov edx, eax
  and eax, 0aaaaaaaah
  and edx, 055555555h
  shr eax, 1
  add edx, edx		; shl edx,1
  or eax, edx
  mov edx, eax
  and eax, 0cccccccch
  and edx, 033333333h
  shr eax, 2
  lea edx, [4*edx]	; shl edx, 2
  or eax, edx
  mov edx, eax
  and eax, 0f0f0f0f0h
  and edx, 0f0f0f0fh
  shr eax, 4
  shl edx, 4
  or eax, edx
  mov edx, eax
  and eax, 0ff00ff00h
  and edx, 0ff00ffh
  shr eax, 8
  shl edx, 8
  or eax, edx
  mov edx, eax
  shr eax, 16
  shl edx, 16
  or eax, edx
  EXITM <eax>
ENDM
Translate$ MACRO arg, src, dest
  push esi
  push edi
  push ebx
  push ecx
  mov esi, repargA(arg)
  mov ebx, repargA(src)
  mov ecx, repargA(dest)
  Let edi=New$(Len(esi))
  push edi
  .Repeat
	lodsb
	or edx, -1
	.Repeat
		inc edx
		mov ah,[ebx+edx]
	.Until al==ah || !ah
	.if ah
		mov al, [ecx+edx]
	.endif
	stosb
  .Until !al
  pop eax
  pop ecx
  pop ebx
  pop edi
  pop esi
  EXITM <eax>
ENDM

ptEsp=0
PushText MACRO arg, obs:=<0>
Local c1$, c1x$, q$, ct, txLen, tmp$, txRest, pNum
  ifb <arg>
	add esp, ptEsp
	ptEsp=0
	EXITM
  endif
  txLen SIZESTR <arg>
  txRest=(txLen-2) mod 4
  ct=3-txRest
  tmp$ equ <0>
  mov edx, esp
  pNum=0
  While txLen gt 1
	pNum=(pNum shl 8) or tmp$
	txLen=txLen-1
	c1$ SUBSTR <arg>, txLen, 1
	tmp$ CATSTR <">, c1$, <">
	ifidn c1$, <\>
		c1x$ SUBSTR <arg>, txLen+1, 1
		ifidn c1x$, <n>
			tmp$ equ <13>
		endif
	endif
	ifidn c1$, <n>
		c1x$ SUBSTR <arg>, txLen-1, 1
		ifidn c1x$, <\>
			tmp$ equ <10>
		endif
	endif
	ct=ct+1
	if ct ge 4
		if obs
			push not pNum
		else
			push pNum
		endif
		ct=0
		pNum=0
		ptEsp=ptEsp+4
	endif
  Endm
  if obs
	.Repeat
		not byte ptr [edx]
		dec edx
	.Until edx<esp
  endif
ENDM

; opsize for procedures:
; MyCode proc p1, p2
; LOCAL v1, v2
; opsize
; ...
; opsize "MyCode - add 1 for a simple ret, +7 for a stack frame, +10 if local vars are being declared"
; ret
; MyCode endp

opsize macro arg	;; usage: opsize/nop/opsize "nop"
LOCAL LocArg, opsL1, opsL2, opsL3
ifndef OpSizeDD
	.DATA?
	OpSizeDD	dd ?
	.CODE
;	echo dd defined
endif
ifb <arg>
;	echo IsBlank
	call opsL1
opsL1:
	pop OpSizeDD   ; contains EIP of pop instruction
else
	flag SUBSTR <arg>, 2,1
	ifidn flag, <:>
		LocArg CATSTR <">, @SubStr(<arg>, 3)
		LocLen SIZESTR LocArg
		LocIns SUBSTR LocArg, 2, LocLen-2
;		tmp$ CATSTR <TheSize=>, %LocLen, <, Ins=>, LocIns
;		% echo tmp$
;		echo IsBlank
		call opsL2
opsL2:
		pop OpSizeDD   ; contains EIP of pop instruction
		LocIns
;		echo we got a flag
;		% echo flag
;		% echo LocArg
;		.err
	else
		LocArg equ <arg>
;		tmp$ CATSTR <TheOldArg=>, LocArg
;		% echo tmp$
	endif
;	echo IsNotBlank <arg>
	call opsL3
opsL3:
	push eax
	mov eax, [esp+4]
	sub eax, 11
	sub OpSizeDD, eax   ; contains EIP of pop instruction
	neg OpSizeDD
	pop eax
	add esp, 4
	pushad
	Print Chr$(13, 10, 32)
	Print Str$(OpSizeDD)
	Print Chr$(9, LocArg)
	popad
endif
ENDM

Kill MACRO arg
  push ecx
  push repargA(arg)
  call DeleteFile
  pop ecx
ENDM

MbLMR$ equ MbLMR
MbLMR$ PROTO :DWORD, :DWORD, :SDWORD
wLeft$ MACRO pStr:REQ, ctArg
  push 1								;; flag left$
  ifb <ctArg>
	push 1							;; default: 1 byte
  else
	PPM31 = 80000000h
	PushPlusMinus ctArg
  endif
  PushString pStr						;; ex MbPushArg pStr
  call MbLMR$
  EXITM <Use_mov_z$_Left$>
ENDM

wRight$ MACRO pStr:REQ, ctArg
  push -1			;; flag right$
  ifb <ctArg>
	push 1							;; default: 1 byte
  else
	PPM31 = 80000000h
	PushPlusMinus ctArg
  endif
  PushString pStr
  call MbLMR$
  EXITM <Use_mov_z$_Left$>
ENDM

wMid$ MACRO pStr:REQ, mstart:REQ, ctArg
  if (opattr mstart) eq atImmediate
	PushPlusMinus mstart*2-1		;; >=1: flag mid$
  else
	PushPlusMinus mstart
	shl stack, 1
	dec stack
  endif
  ifb <ctArg>
	push 80FFFFFFh				;; get me all the rest, 24 bits
  else
	PPM31 = 80000000h
	PushPlusMinus ctArg
  endif
  PushString pStr
  call MbLMR$
  EXITM <Use_mov_z$_Left$>
ENDM

Left$ MACRO pStr:REQ, ctArg
  push 1								;; flag left$
  ifb <ctArg>
	push 1							;; default: 1 byte
  else
	PushPlusMinus ctArg
  endif
  PushString pStr						;; ex MbPushArg pStr
  call MbLMR$
  EXITM <Use_mov_z$_Left$>
ENDM

Mid$ MACRO pStr:REQ, mstart:REQ, ctArg
  PushXPM mstart		;; >=1: flag mid$
  ifb <ctArg>
	push -1							;; get me all the rest
  else
	PushPlusMinus ctArg
  endif
  PushString pStr
  call MbLMR$
  EXITM <Use_mov_z$_Left$>
ENDM

Right$ MACRO pStr:REQ, ctArg
  push -1			;; flag right$
  ifb <ctArg>
	push 1							;; default: 1 byte
  else
	PushPlusMinus ctArg
  endif
  PushString pStr
  call MbLMR$
  EXITM <Use_mov_z$_Left$>
ENDM

Ltrim$ MACRO pStr
  push 1
  PushString pStr
  call MbTrim
  EXITM <( eAx)>
ENDM
wLtrim$ MACRO arg
  EXITM wRec$(Ltrim$(arg))
ENDM
Rtrim$ MACRO pStr
  push 2
  PushString pStr
  call MbTrim
  EXITM <( eAx)>
ENDM
wRtrim$ MACRO arg
  EXITM wRec$(Rtrim$(arg))
ENDM
Trim$ MACRO pStr
  push 3
  PushString pStr
  call MbTrim
  EXITM <( eAx)>
ENDM
wTrim$ MACRO arg
  EXITM wRec$(Trim$(arg))
ENDM
Qtrim$ MACRO pStr	; trim quotes, i.e. Asc 34
  push 3+4
  PushString pStr
  call MbTrim
  EXITM <( eAx)>
ENDM
wQtrim$ MACRO arg
  EXITM wRec$(Qtrim$(arg))
ENDM
Ntrim$ MACRO pStr	; trim everything below numbers
  push 3+8
  PushString pStr
  call MbTrim
  EXITM <( eAx)>
ENDM
MbPushArg macro pString:REQ		;; for MbTrim and MbLMR$
LOCAL sc
  ifidn <pString>, <( eAx)>
  	push 0										;; flag slot number; current slot is src, end int src+1 or src0
  else
  	ifdifi <pString>, <eax>
		ifidn <MbC:>, <pString>
			push Cat$(pString)			;; clipboard, not -111 here
		else
			sc INSTR <pString>, <Use_Let>
			if sc
				% echo *** pString ***
				.err
			else
				push repargA(pString)		;; push pointer to source string
			endif
		endif
	else
		push eax
	endif
	; end in offset MbBufferStart not relevant for this src but keep for dest and mov edi, Left$()
  endif
ENDM

; Candidates for discardable heapmem: MbUpperLowerP, Replace$, FileRead$, String$, wChr$
; MbZeroString and FileReadP
New$ MACRO bytes
  ifdifi <bytes>, <eax>
	if @InStr(1,<bytes>,<Use_>)
		tmp$ CATSTR <## line >, %@Line, <: not allowed ##>
		% echo tmp$
		.err
	else
		mov eax, bytes
	endif
  endif
  call NewStrP
  EXITM <Use_Let>
ENDM
Resize MACRO DestBytes
Local is, d$, oa, r32
  is INSTR <DestBytes>, <:>
  ife is
	tmp$ CATSTR <## Resize, line >, %@Line, <: use some$:bytes ##>
	% echo tmp$
	.err
  else
	d$ SUBSTR <DestBytes>, 1, is-1
	ifdifi d$, <ecx>
		push ecx
	endif
	ifdifi d$, <esi>
		push esi
	endif
	push @SubStr(<DestBytes>, is+1)	; bytes
	oa = opattr d$
	if oa ne atRegister
		mov edx, d$
		r32 equ <edx>
	elseifidni d$, <esi>
		mov edx, d$
		r32 equ <edx>
	else
		r32 equ d$
	endif
	mov esi, offset MbHeapTable
	.Repeat
		lodsd
	.Until r32==eax || esi>offset MbHeapTable+4*MbHeapStrings
	ExternDef MbError3:NEAR
	jne MbError3
	push r32
	push HEAP_ZERO_MEMORY
	push MbProHeap
	call HeapReAlloc
	mov [esi-4], eax
	ifdifi d$, <esi>
		pop esi
	endif
	ifdifi d$, <ecx>
		pop ecx
	endif
	if oa eq atRegister
		xchg eax, d$
	else
		mov d$, eax
	endif
  endif
ENDM
Replace$ MACRO src, search, repl, flags	:=<0>, ct:=<0>
  push flags+256*ct
  MbPushArg repl
  MbPushArg search
  MbPushArg src
  call MbReplPrep			; does not allocate any mem
  EXITM <Use_Let>
ENDM

Ztrim$ macro arg:REQ
LOCAL tmp$
;; dummy macro - Masm strings are zero-delimited by default
  tmp$ equ <arg>
  EXITM tmp$
ENDM

wLower$ MACRO src
  push 2
  PushString src
  call MbUpperLowerP
  EXITM <Use_Let>
ENDM

wUpper$ MACRO src
  push 3
  PushString src
  call MbUpperLowerP
  EXITM <Use_Let>
ENDM

Lower$ MACRO src
  push 0
  PushString src
  call MbUpperLowerP
  EXITM <Use_Let>
ENDM

Upper$ MACRO src
  push 1
  PushString src
  call MbUpperLowerP
  EXITM <Use_Let>
ENDM

Chr$ MACRO TheArgs:VARARG
Local ct, c1, qu, spos, NewString, ctIns, ctImm, hasP, hasM, offsetPM, arg, hasO, oa, is, tmp$, xchgEaxEdi
  ctIns = 0
  ctImm = 0
  spos = 0
  argsize = 0
  hasP=0
  hasM=0
  TheString equ <>
  TheInserts equ <>
  xchgEaxEdi equ <>
  FOR argx, <TheArgs>
	arg CATSTR <argx>, <   >
	argsize SIZESTR <argx>
	qu = 1
	c1 SUBSTR arg, 1, 1
	ifidn c1, <">
		qu = argsize - 2
	endif
	ifidn c1, <'>
		qu = argsize - 2
	endif
	is INSTR arg, <]>
  	hasP INSTR is+1, arg, <+>
  	hasM INSTR is+1, arg, <->
	hasO = hasP or hasM
  	if hasO and qu eq 1
  		offsetPM SUBSTR arg, hasO+1
  		arg SUBSTR arg, 1, hasO-1
		argsize = hasO-1
  	endif
	oa = (opattr(arg)) AND 127
	if (oa eq 36) or (oa eq 0)					; immediate
		spos = spos + qu
		TheString CATSTR TheString, <, >, arg
		ctImm = ctImm + 1
	elseif oa eq 48								; register
		if argsize eq 3			;; full size register
			c1 SUBSTR arg, 3, 1
			ifidni c1, <x>
				tmp$ SUBSTR arg, 2, 1
				tmp$ CATSTR tmp$, <l>
			else
				TheInserts CATSTR TheInserts , <mov eax, >, arg, <#@>		;; esi, ebp, edi
				ctIns = ctIns + 1
				tmp$ equ <al>
			endif
		else
			tmp$ equ arg
		endif
		is INSTR tmp$, <edi>
		if is
			xchgEaxEdi equ <xchg eax, edi>
			tmp$ equ <eax>
		endif
		TheInserts CATSTR TheInserts , <mov [edi+>, %spos, <], >, tmp$, <#@>
		if hasP
			TheInserts CATSTR TheInserts , <add byte ptr [edi+>, %spos, <], >, offsetPM, <#@>
			ctIns = ctIns + 1
		elseif hasM
			TheInserts CATSTR TheInserts , <sub byte ptr [edi+>, %spos, <], >, offsetPM, <#@>
			ctIns = ctIns + 1
		endif
		TheString CATSTR TheString, <, "x">
		ctIns = ctIns + 1
		spos = spos + 1
	elseif (oa eq 42) or (oa eq 98) or (oa eq atMemory)	; global or local
		is INSTR arg, <PTR [ebx+>
		if is
			tmp$ SUBSTR arg, is+4
			TheInserts CATSTR TheInserts , <mov al, >, tmp$, <#@>
		else
			TheInserts CATSTR TheInserts , <mov al, byte ptr arg>, <#@>
		endif
		if hasP
			TheInserts CATSTR TheInserts , <add al, >, offsetPM, <#@>
			ctIns = ctIns + 1
		elseif hasM
			TheInserts CATSTR TheInserts , <sub al, >, offsetPM, <#@>
			ctIns = ctIns + 1
		endif
		TheInserts CATSTR TheInserts , <mov [edi+>, %spos, <], al>, <#@>
		TheString CATSTR TheString, <, "_">
		ctIns = ctIns + 2
		spos = spos + 1
	else
		argsize SIZESTR arg
		tmp$ CATSTR arg, <: >, %argsize, < is wrong size >
		% echo **** tmp$ ***
		.err
	endif
  ENDM
  if ctImm
	.DATA
	TheString SUBSTR TheString, 3
	NewString db TheString, 0
	.CODE
  else
	ifndef Buffer4Chr$
		.DATA?
		Buffer4Chr$ db 20 dup(?)				;; no more then 20-3 args, please
	endif
	NewString equ <Buffer4Chr$>
	.CODE
  endif
  if ctIns
	push edi
	xchgEaxEdi
	mov edi, OFFSET NewString
	WHILE ctIns gt 0
		ct INSTR TheInserts, <#@>
		ctIns = ctIns - 1
		tmp$ SUBSTR TheInserts, 1, ct-1
		tmp$
		ife ctIns
			mov byte ptr [edi+spos], 0
			EXITM
		endif
		TheInserts SUBSTR TheInserts, ct+2
	ENDM
	xchg eax, edi
	pop edi
  endif
  EXITM <OFFSET NewString>
ENDM
MbWideStr = 0	; must be in front of wStr$
wStr$ MACRO TheArgs:VARARG
  MbWideStr=1
  EXITM Str$(TheArgs)
ENDM

; --------  FloatAndCalc mac start ------------ (select all with F3)
ChkNum macro argX:REQ   ;; sets aPass$ for pushing, exits with NumSize
LOCAL ArgType, tmp$, tmp2$, arg, cnReal, dot, deco, isL, isP, xmmfloat
  sbw=0
  arg equ <argX>	;; sizes: 0=fild, 1=R4, 2=R8, 3=R10, 4=xmmint, 5=xmmfloat, 6=qword
  aPass$ equ <argX>	;; default: push arg as dword
  xmmfloat INSTR arg, <f:>	;; f:xmm0
  if xmmfloat eq 1
	arg SUBSTR arg, 3
	aPass$ equ arg	;; default: push arg as dword
  endif
  NumSize = -1	;; global return value, -1=error
  ifb <argX>
	crash
	EXITM <0>	;; no argument passed
  endif
  dot INSTR arg, < >	;; leading space?
  if dot eq 1
	arg SUBSTR arg, 2	;; strip one leading space
  endif
  dot INSTR arg, <.>	;; immediate real, or variable with dot, e.g. chrg.cpMin?
  if dot
	isL INSTR arg, <[>	;; retval from a structure, e.g [E
  	if isL
  		isP INSTR arg, <+>
  		ife isP
			isP INSTR arg, <]>		;; [Esi.FLOATSTRUC.f4]
  		endif
  		if dot gt isL
	  		tmp$ SUBSTR arg, isL+5, isP-isL-5
  		else
	  		tmp$ SUBSTR arg, 1, isL-1
  		endif
		isL INSTR isP, arg, <.>		; second dot, e.g. SetGlobals with struct?
		if isL gt isP
  			tmp2$ SUBSTR arg, isL
  			tmp$ CATSTR tmp$, tmp2$
		endif
			; decide: push the arg itself, or a pointer to the arg?
	  		if (type(tmp$) eq DWORD) or (type(tmp$) eq SDWORD)
	  			NumSize = MbDword
	  		elseif (type(tmp$) eq WORD) or (type(tmp$) eq SWORD)  ;; needs wp flag
	  			NumSize = MbDword
	  			aPass$ CATSTR <wp:>, arg
	  		elseif type(tmp$) eq BYTE		;; byte: needs bp flag
	  			NumSize = MbDword
	  			aPass$ CATSTR <bp:>, arg
	  		elseif type(tmp$) eq REAL4		;; dword or real4: direct push
	  			NumSize = MbReal4
	  		elseif type(tmp$) eq REAL8
	  			NumSize = MbReal8
			 	aPass$ equ <pupo>			;; others: push a pointer to the var
	  		elseif type(tmp$) eq REAL10
	  			NumSize = MbReal10
			 	aPass$ equ <pupo>
	  		elseif type(tmp$) eq QWORD
	  			% echo x=<argX>
	  			NumSize = MbQword
			 	aPass$ equ <pupo>
	  		else
	  			% echo unknown type: tmp$
	  			.err
			endif
			EXITM %NumSize
 	endif
  	tmp$ SUBSTR arg, dot+1, 1	; myvar2.left possible, myvar.2 not
  	dot INSTR <0123456789>, tmp$
;  	echo HasDot=%dot
  endif
  twocolons INSTR arg, <::>
  if twocolons
	aPass$ equ <offset MbTmpQw>
  	NumSize = MbQword
	EXITM %NumSize
   elseif dot
	.DATA
	isP SIZESTR arg
	if (DefNumDigits ge 16) or (isP ge 16)
		cnReal REAL10 arg						;; write arg to data section
		.CODE
		NumSize = MbReal10
		if isP gt 20
			tmp$ CATSTR <## line >, %@Line, <: max precision is 19 digits, requested >, %(isP-1), < ##>
			% echo tmp$
		endif
	else
		cnReal REAL8 arg
		.CODE
		NumSize = MbReal8
	endif
	aPass$ equ <offset cnReal>				;; we pass it as a pointer to the new Real8
  else											;; neither edx::eax nor immediate Real8
	ArgType = (opattr(arg)) AND 127			;; 0 no vn$, 34 mem, 36 immediate, 42 global, 48 CPU register, 98 local
	ifidn arg, emArr$
	elseif ArgType eq atLocal or ArgType eq atGlobal or ArgType eq atMemory
		isP = MbDword					; default
;		tmp$ CATSTR <Myarg=>, <arg>, < with_type >, %ArgType
;		% echo tmp$
  		if type(arg) eq REAL4
  			isP = MbReal4
  			IsReal = 1
  		elseif type(arg) eq REAL8
  			isP = MbReal8
			lea eax, arg
			aPass$ equ eax		; LOCAL arg trashes eax
  		elseif type(arg) eq REAL10
  			isP = MbReal10
			lea eax, arg
			aPass$ equ eax
  		elseif type(arg) eq 8		; must be the number 8
  			isP = MbQword		; QWORD, SQWORD, LARGE_INTEGER, ... but not REAL8 (above)
			lea eax, arg
			aPass$ equ eax
  		elseif (type(arg) eq WORD) or (type(arg) eq SWORD)
  			sbw=type(arg) eq SWORD
  			aPass$ CATSTR <wp:>, arg	; special flag to Str$
  		elseif (type(arg) eq BYTE) or (type(arg) eq SBYTE)
  			sbw=type(arg) eq SBYTE
  			aPass$ CATSTR <bp:>, arg	; special flag to Str$
		endif
		NumSize = isP
		EXITM %isP
	elseif (ArgType eq atImmediate) or (ArgType eq atOffset)
		NumSize = 0			;; immediate integer, push directly as dword
	elseif ArgType eq atRegister
		RealSize SIZESTR arg
;		tmp$ CATSTR <Reg: >, arg, < with >, %RealSize
;		% echo tmp$
		NumSize = 0			;; register as int32
		if RealSize ge 3			;; full size register
			tmp$ SUBSTR arg, 1, 3
			ifidni <xmm>, tmp$		; xmm0, XMM(0)
				is INSTR arg, <(>
				if is
					tmp$ SUBSTR arg, 5, 1	; mlv615
				else
					tmp$ SUBSTR arg, 4, 1
				endif
				if xmmfloat
					NumSize = MbXmmR
				else
					NumSize = MbXmmI
				endif
				RealSize = 20+tmp$		; xmm0...7, even for 64-bit integer, odd for REAL8
				aPass$ equ RealSize
			endif
		else
			is INSTR arg, <x>
			if is eq 2
				aPass$ CATSTR <wp:>, arg
			else
				aPass$ CATSTR <bp:>, arg
			endif
		endif
	else
		tmp$ CATSTR <UNKNOWN=>, arg
		% echo tmp$
	endif
  endif
  if NumSize lt 0
	 tmp$ CATSTR arg, < is type >, %ArgType, < with size >, %NumSize
	% echo tmp$
	.err
  endif
  EXITM <NumSize>
ENDM
MbArg macro arg
  ifidn emArr$, <arg>	;; Array??
	EXITM <127>
  elseifidn <Use_mov_z$_Left$>, <arg>	;; Left$ etc?
	push 0
	call MbGetSlotPointer
	EXITM <[edx]>
  else
	EXITM repargA(arg)	;; normal string
  endif
ENDM
MovVal MACRO dest, src
LOCAL partreg32, is
  % is INSTR <dest>, <ptr [Edx>
  if is
	ifidn <src>, emArr$
		imul eax, stLastEl, stSizeG
		add eax, [NumArrTable+4*stLastIDs]
			invoke MbVal, 127, eax, stLastType
		EXITM
	endif
  endif
  ife ChkNum(dest)
	partreg32 INSTR aPass$, <p:>		; wp:, bp: aka MbWord, MbByte
	if partreg32
		partreg32 INSTR aPass$, <bp:>
		aPass$ SUBSTR aPass$, 4
		ife partreg32
			partreg32 = 2				; wp:, MbWord
		endif
	endif
	ifidn aPass$, <ST(0)>
		invoke MbVal, MbArg(src), eax, MbST0
	else
		is INSTR aPass$, <ptr [Edx>		; a structure element
		if is
			push edx
		endif
		invoke MbVal, MbArg(src), eax, 0
		if is
			pop edx
		endif
		ifdifi <dest>, <eax>
			if partreg32 eq 2
				ifdifi <dest>, <ax>
					mov dest, ax
				endif
			elseif partreg32 eq 1
				ifdifi <dest>, <al>
					mov dest, al
				endif
			else
				mov dest, eax
			endif
		endif
 	endif
  elseif NumSize eq MbReal4		;; Str$ pushes the R4 directly, no good here(?)
	invoke MbVal, MbArg(src), addr dest, NumSize	;; addr allows [edx..]
  elseifidn aPass$, <pupo>
	lea edx, dest
	invoke MbVal, MbArg(src), edx, NumSize
  else
	invoke MbVal, MbArg(src), aPass$, NumSize
  endif
ENDM
MbF2Asc equ <Float2Asc>
twocolons=0
Str$ MACRO strformat, num
LOCAL is, isL, isR, P$, PP, PP_o, parseLen, c$, AriMult, CurAri, LastAri
LOCAL NegFlag, CurNum$, argct, HasDot, popST
LOCAL f2sMS, ArgType, tmp$, FF$, quotes
  HasDot	= 0	;; immediate reals, 1.234e44
  NegFlag	= 0	;; if args starts with -
  f2sMS	= 0	;; combined mode and size parameter
  argct	= 0	;; argument counter (4 num args max)
  PP	= 0	;; startpos in parse$
  PP_o	= 1	;; ParsePos old
  LastAri	= 0	;; prev mode, e.g. 123+MyInt* when * is found
  AriMult	= 1	;; ari multiplier
  IsReal	= 0	;; global default: integer
  popST	= 0
  ifb <num>
	% P$ CATSTR <strformat>, <#>	;; first arg is not format but the number itself
  else			;; JWasm (2.05, 1/2011) chokes if % is not used
	% P$ CATSTR <num>, <#>	;; first arg is a format string from the slot pool
	  ifidn <strformat>, <( eAx)>
		FF$ equ 127
	  elseifidn <strformat>, emArr$
		FF$ equ 127
	  elseifidni <strformat>, <"%u">
		FF$ equ -1	;; default unsigned integer
	  elseifidni <strformat>, <"%i">
		FF$ equ 1	;; default integer
	  elseifidni <strformat>, <"%f">
		FF$ equ 0	;; default real
	  else
		quotes INSTR <strformat>, <'>
		if quotes ne 1
			quotes INSTR <strformat>, <">
		endif
		if quotes eq 1
			FF$ CATSTR repargA(<strformat>)
		else
			is INSTR <strformat>, <#e>
			if is
				FF$ SUBSTR <strformat>, 2
			else
				is INSTR <strformat>, <OFFSET>		; brackets: Chr$("Test", 40, "%i", 41)
				if is eq 1
					FF$ SUBSTR <strformat>, 1
				else
					% echo ## invalid Str$ strformat ##
					.err
				endif
			endif
		endif
	  endif
  endif
  parseLen SIZESTR P$
  isL INSTR P$, <[>
  ; tmp$ CATSTR <We scan >, P$, <, >, %parseLen, < bytes, >, %isL
  ; % echo tmp$
  WHILE PP lt parseLen	; Repeat until Parse Position >= LEN(P$)
	PP=PP+1	; Position in Parse$
	c$ SUBSTR P$, PP, 1
	CurAri INSTR <+-*/#.eE[>, c$	; 1234; and 8: neg before continuing
	if (CurAri eq 1) or (CurAri eq 2) or (CurAri eq 9)	;; contains a plus or minus, could be structure element - if yes, ignore the plus
		isR INSTR PP, P$, <]>
		if isL and (isR gt PP) and (isL le PP)
			CurAri=-127				; there is a special arg
		endif
		if PP GT PP_o
			tmp$ SUBSTR P$, PP_o, PP-PP_o
			is INSTR tmp$, <::>	; ML needs it
			ife is
				if (opattr tmp$) eq atLocal
					CurAri=0
				endif
			endif
		endif
	endif
	if CurAri eq 2
		if PP eq PP_o					; first arg starts with minus?
			NegFlag=40000000h	; set bit 30
			CurAri=0					; pretend there is no arg
			PP_o=PP+1
		endif
	endif
	if CurAri eq 6		;; dot
		tmp$ SUBSTR P$, PP+1, 1
		if @InStr(1, "0123456789", tmp$)
			HasDot=1
			IsReal=1		;; structure element might not be real
		endif
		CurAri=0
	endif
	if CurAri gt 6				;; e, E
		CurAri=0
		tmp$ SUBSTR P$, 1, PP
		if HasDot
			PP = PP + 1		;; skip 123e+1
		endif
	endif
	if CurAri
		if CurAri eq -127
			if PP gt 4
			c$ SUBSTR P$, PP-4, 3	; could be anysize ptr [...]
			endif
		ifdifi c$, <PTR>	; Dim returns lower case ptr
			CurNum$ SUBSTR P$, isL, isR-isL+1
			c$ SUBSTR P$, isR+1, 1
			ifidn <.>, c$	; [esi.RECT].right?
					CurNum$ SUBSTR P$, isL, isR-isL
					isL=isR+1
					is=0
					While is eq 0			;; we need a new CurAri
						isR=isR+1		;; Position in Parse$
						c$ SUBSTR P$, isR, 1
						is INSTR <+-*/#>, c$		;; simple ari or end
					ENDM
					c$ SUBSTR P$, isL, isR-isL
					is INSTR CurNum$, <+>
					ife is
						is INSTR CurNum$, <->
					endif
					if is
						tmp$ SUBSTR CurNum$, is
						CurNum$ SUBSTR CurNum$, 1, is-1
						CurNum$ CATSTR CurNum$, c$, tmp$, <]>
					else
						CurNum$ CATSTR CurNum$, c$, <]>
					endif
					isR=isR-1
			endif
			else
				isL=isL-9
				WHILE (isL ge 1) and PP		; e.g. BYTE ptr [Edx+2]*WORD ptr [Edx+2]
				  isL=isL-1
				  if isL
					  c$ SUBSTR P$, isL, 1	; list of valid chars
					  PP INSTR <SQOWORDBYTEREAL4810>, c$
					  ife PP
						  PP INSTR <sqowordbytereal4810>, c$	; 1/2012
					  endif
				  endif
				ENDM
				CurNum$ SUBSTR P$, isL+1, isR-isL		; startpos, length
			endif
		PP=isR	;; target the char after ]
			isL INSTR PP, P$, <[>		;; reload
		CurAri=0	;; reset to what???
		While CurAri eq 0	;; we need a new CurAri
				PP=PP+1						;; Position in Parse$
				c$ SUBSTR P$, PP, 1
				CurAri INSTR <+-*/#.eE>, c$
			ENDM
		else
			CurNum$ SUBSTR P$, PP_o, PP - PP_o
			is INSTR CurNum$, <ST(>
			if is eq 1
				popST INSTR is+1, CurNum$, <)v>
				if popST
					CurNum$ SUBSTR CurNum$, 1, popST
				endif
				fxch CurNum$
				ffree st(7)
				fld st
				fstp MbDebugR10
				fxch CurNum$
				CurNum$ equ MbDebugR10
			endif
		endif
		CurMS = LastAri + 8 * ChkNum(CurNum$)
		if NumSize ge MbReal4 and NumSize le MbXmmR
			IsReal = 1
		endif
		f2sMS = f2sMS + AriMult * CurMS	;; mode (bits 0-2, 0-7) and NumSize (bits 3-5, 8*(0-3), bit 6 reserved)
		LastAri = CurAri
;		tmp$ CATSTR <## We push >, aPass$, < with numsize >, %NumSize
;		% echo tmp$
		ifidn aPass$, <pupo>
			lea edx, CurNum$
			push edx
		else
			is INSTR aPass$, <p:>	; wp:, bp: aka MbWord, MbByte
			if is
				is INSTR <strformat>, <%u>
				if is
					sbw=0			; force unsigned
				endif
				tmp$ SUBSTR aPass$, 4
				c$ SUBSTR aPass$, 1, 1
				push eax	; save eax and create a dword slot
				ifidni c$, <b>
					if sbw
						tmp$ CATSTR <movsx eax, byte ptr >, tmp$
					else
						tmp$ CATSTR <movzx eax, byte ptr >, tmp$
					endif
				else
					if sbw
						tmp$ CATSTR <movsx eax, word ptr >, tmp$
					else
						tmp$ CATSTR <movzx eax, word ptr >, tmp$
					endif
				endif
				tmp$
				xchg eax, [esp]			; very slow but it's a rare case
			else
				if twocolons		; global from chknum
					tmp$ SUBSTR CurNum$, twocolons+2	; edx::eax
					mov dword ptr MbTmpQw[0], tmp$
					tmp$ SUBSTR CurNum$, 1, twocolons-1	; edx::eax
					mov dword ptr MbTmpQw[4], tmp$
				endif
				push aPass$
			endif
		endif
		AriMult = AriMult * 64		;; 5*6=30: 0...7 sizes: 0=fild, 1=R4, 2=R8, 3=R10, 0...7 ari, 8=neg 000 001 010 011 100 101 110 111
		argct = argct + 1
		if argct eq 6
			echo too many arguments
			.err
		endif
		PP_o = PP+1
		HasDot = 0
	endif
  ENDM
  ifndef FF$
	if IsReal
		if AriMult eq 64 and NumSize eq MbReal10 and DefNumSet eq 0
			FF$ equ 3 
		elseif AriMult eq 64 and (NumSize eq MbReal8 or NumSize eq MbXmmR and DefNumSet eq 0)
			FF$ equ 2
		else
			FF$ equ 0
		endif
	else
		FF$ equ <1>
	endif
  endif
  if MbWideStr
	MbWideStr = 0
	f2sMS=f2sMS or 80000000h	; negative f2sMS means wide output needed
  endif
  push argct+4
  push f2sMS or NegFlag
  push FF$
  call MbF2Asc	;; invoke Float2Asc, FF$, f2sMS, argct+4
  if popST
	fstp st
  endif
  EXITM <( eAx)>	;; the blank left of eAx is an important flag
ENDM
ValLeft equ <MbPosVal>
ValRight equ <MbPosVal[4]>
Val MACRO src, vpos
  ifnb <vpos>
	ifndef MbPosVal
		.DATA?
		MbPosVal dd ?, ?
		.CODE
	endif
	push esi
	push vpos
	mov esi, MbArg(src)
	xor edx, edx
	sub stack, 2
	.if !Sign?
		.Repeat
			.Repeat
				lodsb
				inc edx
			.Until al<="," || al=="/" || al==":"	; !"#$%&'()*+,-./0..9:
			.Break .if !al
			.Repeat
				lodsb
				inc edx
			.Until al>="+" && al<="9" || !al
			dec stack
		.Until Sign?
		dec esi
	.endif
	push edx
	; deb 4, "used", $esi
	invoke MbVal, esi, esp, 0
	pop esi
	mov MbPosVal, esi
	add esi, edx
	mov MbPosVal[4], esi
	pop esi
	pop esi
	EXITM <eax>
  endif
  if sLine eq @Line
	push edx
  endif
  invoke MbVal, MbArg(src), esp, 0	; NumSize 0: reg32 or dword; esp=discarded dest
  if sLine eq @Line
	pop edx
  endif
  EXITM <eax>
ENDM
Sqrt MACRO arg1:REQ, dest:=<MbDebugR10>
LOCAL oa, is, prefix, arg
  is INSTR <arg1>, <:xmm>	; only valid code is f:xmmx
  arg SUBSTR <arg1>, is+1
  oa = ChkNum(arg)
  ffree st(7)
  oa = (opattr arg) AND 127
  if (oa eq 36) or (oa eq 48)
	arg CATSTR arg, < >
	prefix SUBSTR arg, 1, 2
		if is eq 2
			movlps REAL8 ptr MbDebugR10, arg
			fld REAL8 ptr MbDebugR10
	elseifidni prefix, <xm>
			movlps QWORD ptr MbDebugR10, arg
			fild REAL8 ptr MbDebugR10
		else
		push arg
		fild stack	; immediate integer or reg32 on stack, then on FPU
		add esp, 4
	endif
  else
	if NumSize eq MbReal4
			fld arg		; single, Real4
	elseif NumSize eq MbQword
			fild arg
		else
		is = SIZEOF arg
		if SIZEOF arg eq 4
				fild arg
			elseif SIZEOF arg eq 2	; word vars are ok
				fild word ptr arg
			else
				fld arg		; R8, R10
			endif
		endif
  endif
  fsqrt
  ifdif <dest>, <ST(0)>
	fstp dest
  endif
  EXITM <dest>
ENDM
; --------  FloatAndCalc mac end ------------ (select all with F3)

Asc MACRO arg
LOCAL sc
;; only eax trashed - returns BYTE
  sc INSTR <arg>, <Use_mov>
  if sc eq 1
	push 0
	call MbGetSlotPointer
	mov eax, [edx]
  elseifdifi <arg>, <eax>
	mov eax, arg
  endif
  mov al,  [eax]
  EXITM <al>
ENDM

Cvi MACRO arg
LOCAL sc
;; only eax trashed - returns WORD
  sc INSTR <arg>, <Use_mov>
  if sc eq 1
	push 0
	call MbGetSlotPointer
	mov eax, [edx]
  elseifdifi <arg>, <eax>
	mov eax, arg
  endif
  mov ax, [eax]
  EXITM <ax>
ENDM

Cvl MACRO arg
LOCAL sc
;; only eax trashed - returns DWORD
  sc INSTR <arg>, <Use_mov>
  if sc eq 1
	push 0
	call MbGetSlotPointer
	mov eax, [edx]
  elseifdifi <arg>, <eax>
	mov eax, arg
  endif
  mov eax, [eax]
  EXITM <eax>
ENDM

Abs MACRO arg
	push arg
	test byte ptr [esp+3], 128
	pop eax
	.if Sign?
		neg eax
	.endif
	EXITM <eax>
ENDM
Min MACRO arg1:REQ, TheArgs:VARARG	; Min(9, eax-1) is legal syntax
LOCAL reg$, is
  reg$ equ <edx>
  is INSTR <TheArgs>, reg$
  if is
	reg$ equ <eax>
  endif
  ifdifi <arg1>, reg$	; uses edx because eax is often return value of e.g. My$(?)
	if (opattr arg1) eq 36
		if (arg1 le 127) and (arg1 ge -128)
				push arg1
				pop reg$
		else
				mov reg$, arg1
		endif
	else
		mov reg$, arg1
	endif
  endif
  FOR arg, <TheArgs>
  	if @InStr(1, arg, <->) or @InStr(1, arg, <+>)
  		PushPlusMinus arg
	  	.if sdword ptr reg$<=[esp]
	  			mov [esp], reg$
	  	.endif
  		pop reg$
  	else
	  	.if sdword ptr reg$>arg
	  			mov reg$, arg
	  	.endif
  	endif
  ENDM
  EXITM reg$
ENDM

Max MACRO arg1:REQ, TheArgs:VARARG
LOCAL reg$, is
  reg$ equ <edx>
  is INSTR <TheArgs>, reg$
  if is
	reg$ equ <eax>
  endif
  ifdifi <arg1>, reg$	; uses edx because eax is often return value of e.g. My$(?)
	if (opattr arg1) eq 36
		if (arg1 le 127) and (arg1 ge -128)
				push arg1
				pop reg$
		else
				mov reg$, arg1
		endif
	else
		mov reg$, arg1
	endif
  endif
  FOR arg, <TheArgs>
  	if @InStr(1, arg, <->) or @InStr(1, arg, <+>)
  		PushPlusMinus arg
	  	.if sdword ptr reg$>=[esp]
	  			mov [esp], reg$
	  	.endif
  		pop reg$
  	else
	  	.if sdword ptr reg$<arg
	  			mov reg$, arg
	  	.endif
  	endif
  ENDM
  EXITM reg$
ENDM

Odd MACRO arg
LOCAL oa, is, Reg16, tmp$
  tmp$ SUBSTR <arg>, 2, 1
  is INSTR <abcd>, tmp$	; Odd(ebx): test bl, 1
  tmp$ CATSTR <test >, tmp$, <l, 1>
  if is and ((opattr arg) eq atRegister)
	tmp$
  else
	test arg, 1
  endif
  EXITM <!Zero?>
ENDM
; ---------------- date and time ----------------
wTimeMac macro MacLine
  if MacLine ne MacLineTime
	invoke MbDTF$, MbT@+1, 0
	MacLineTime = MacLine
  endif
  EXITM emArr$
ENDM
wTime$ equ wTimeMac(@Line)

wDateMac macro MacLine
  if MacLine ne MacLineDate
	invoke MbDTF$, MbD@+1, 0
	MacLineDate = MacLine
  endif
  EXITM emArr$
ENDM
wDate$ equ wDateMac(@Line)

TimeMac macro MacLine
  if MacLine ne MacLineTime
	invoke MbDTF$, MbT@, 0
	MacLineTime = MacLine
  endif
  EXITM emArr$
ENDM
Time$ equ TimeMac(@Line)

DateMac macro MacLine
  if MacLine ne MacLineDate
	invoke MbDTF$, MbD@, 0
	MacLineDate = MacLine
  endif
  EXITM emArr$
ENDM
Date$ equ DateMac(@Line)
; -------------- create date+time ------
MacLineCDate =	0
MacLineDate =	0
MacLineCTime =	0
MacLineTime =	0
MacLineTimer =	0

CrtTimeMac macro MacLine
LOCAL tmp$
  if MacLine ne MacLineCTime
	ifndef mcCrtTimeBuf
	  tmp$ CATSTR <">, @Time, <">
	.DATA
	  mcCrtTimeBuf db tmp$, 0
	.CODE
	endif
	MacLineCTime = MacLine
  endif
  EXITM <offset mcCrtTimeBuf>
ENDM
CrtTime$	equ CrtTimeMac(@Line)

CrtDateMac macro MacLine
LOCAL tmp$, cdD, cdM, cdY, is
  if MacLine ne MacLineCDate
	ifndef mcCrtDateBuf
		is INSTR @Date, <->
		if is eq 5
			echo ASMC
			cdD SUBSTR @Date, 9, 2
			cdM SUBSTR @Date, 6, 2
			cdY SUBSTR @Date, 1, 4
			tmp$ CATSTR <">, cdD, <.>, cdM, <.>, cdY, <">
		else
			cdD SUBSTR @Date, 4, 2
			cdM SUBSTR @Date, 1, 2
			cdY SUBSTR @Date, 7, 2
			tmp$ CATSTR <">, cdD, <.>, cdM, <.20>, cdY, <">
		endif
	.DATA
	  mcCrtDateBuf db tmp$, 0
	.CODE
	endif
	MacLineCDate = MacLine
  endif
  EXITM <offset mcCrtDateBuf>
ENDM
CrtDate$	equ CrtDateMac(@Line)

Timer	textequ <TimerMac(@Line)>
TimerMac macro MacLine
  if MacLine ne MacLineTimer
	MacLineTimer = MacLine
	push ecx
	invoke GetTickCount
	pop ecx
  endif
  EXITM <eax>
ENDM

MbNaTiCt=0		; jj2007 23.02.2012
MbNaTiChk=1		; use .if/.endif check - fails only if start and end are in different loops
MbNaTiSleep=1	; improves accuracy
UseCore MACRO CoNum
  invoke SetThreadAffinityMask, rv(GetCurrentThread), 1 shl (CoNum-1)
  ExternDef MbError0:NEAR	; used with WriteFile and SetWin$
  TestRetVal PROTO
  call TestRetVal
  Delay 1	; <--- force to switch mode by dropping current time slice (Alex)
ENDM
NanoTimer MACRO ntUnit
LOCAL CoX$, CoN$, CoMsk
  ifndef MbNanoSecs
	.DATA?
	align 4	; otherwise no access
	MbNanoSecs REAL8 ?
	.CODE
  endif
  MbNaTiCt=MbNaTiCt+1
  if MbNaTiCt and 1
	push ecx
	CoX$ CATSTR <ntUnit>, <     >	; nt(Core 1) or nt(core2) etc
	CoN$ SUBSTR CoX$, 5
	CoX$ SUBSTR CoX$, 1, 4
	ifidni CoX$, <core>
		UseCore CoN$
	elseif MbNaTiSleep
		Delay 1
	endif
	invoke QueryPerformanceCounter, offset MbNanoSecs
	pop ecx
	if MbNaTiChk
	  .if 1
	endif
		EXITM <>
 else
		ffree st(7)
		fild MbNanoSecs
		push ecx
		push eax
		push edx
		invoke QueryPerformanceCounter, esp
		ffree st(7)
		fild qword ptr [esp]
		fsub
		fchs
		MbXms
		invoke QueryPerformanceFrequency, esp	; trashes xmm0...xmm5 on Win7-64, same for SetConsoleCP
		MbXmr
		fild qword ptr [esp]
		pop edx
		fdiv
		ifidni <ntUnit>, <s>
			fstp MbNanoSecs
			pop eax
			pop ecx
			if MbNaTiChk
			  .endif
			endif
			EXITM <MbNanoSecs>
		else
			mov stack, 1000
			fimul stack
			ifnb <ntUnit>
				ifdifi <ntUnit>, <ms>
				    fimul stack	; microseconds
				endif
			endif
			fistp stack
			pop eax
			pop ecx
			if MbNaTiChk
			  .endif
			endif
			EXITM <eax>
		endif
 endif
ENDM

NanoTimer$ MACRO maxnum:=<10000>
  ifndef MbNt$
	.DATA
	if IsUtf8Build()
		MbNt$ db "%i ", -62, 0b5h, "s", 0, 0, "%i ms", 0, 0, 0, "%u s", 0
	else
		MbNt$ db "%i ", 0b5h, "s", 0, 0, 0, "%i ms", 0, 0, 0, "%u s", 0
	endif
	.CODE
  endif
  push edi
  xor edi, edi
  void NanoTimer(µs)
  push 1000
  .While eax>=maxnum && edi<2
	cdq
	idiv stack
	inc edi
  .Endw
  pop edx
  lea edx, MbNt$[8*edi]
  pop edi
  EXITM Str$(#edx, eax)
ENDM
For_	textequ <MbFor>
Next	textequ <MbNext>
Next_	textequ <MbNext>
; For is a reserved word, so we use MbFor, MbNext 
; internally, and the above text equates for easier typing.

bLoopCtMax	= -1	; defines the loop counter, by nesting level and position
MbNext$	equ <x>
MbForReject	= 1	; 0=slightly faster and 2 bytes less
feReg32 equ <edi>
feR32Warn=0
MbFnCount=0
ForNextCounter equ <MbFnc()>
MbFnc macro
  MbFnCount=1
  exitm <MbFNC>
ENDM
ifndef MbForMax
  MbForMax	= 20	; adjust if necessary
endif
SetVR macro dest, arg
Local oa
  oa = opattr dest
  if oa ne atRegister
	dest equ <arg>
  endif
ENDM
MbFor MACRO fline					; --- start for_next ---
LOCAL bLoopCtFor, ctStart, ctVar, ctEnd, is, iseq, isto, isstep, ArgType, tmp$, vtE$, otE$, vtS$, otS$, tmpReg
LOCAL tregpush, ctStep, ctStepF, cvType, fEach$, fArr, fOa
  bLoopCtFor=bLoopCtMax+1	;; increase for next nesting level
  bLoopCtMax=bLoopCtFor
  MbNext$ CATSTR %bLoopCtMax, <#>, MbNext$	; #0#1#4#...
  if bLoopCtFor gt MbForMax
	tmp$ CATSTR <## line >, %@Line, <: >, %bLoopCtFor, < For_/Next loops, only MbForMax=>, %MbForMax, < allowed ##>
	.err tmp$
  endif
.Repeat			;; dummy, triggers error if matching .Until in Next not present
  ifndef MbForCounters
	.DATA?
	MbForCounters  dd MbForMax dup(?)
	MbFNC	dd ?
	fcr4		REAL4 ?
	fcr8		REAL8 ?
	fcr10	REAL10 ?
	.CODE
  endif
  MbFnCount=0
  tmp$ SUBSTR <fline>, 1, 4
  ctEach equ <** use with for...each **>
  ifidni tmp$, <each>
			isto INSTR 6, <fline>, <In>
			ife isto
				isto INSTR 6, <fline>, <in>
				ife isto
				  tmp$ CATSTR <## line >, %@Line, <: syntax error, should be for each myVar in myArray() ##>
				  % echo tmp$
				  .err
				endif
			endif
			ifidn stSizeG$, <DWORD>
				SetVR <@SubStr(<fline>, 5, isto-6)>, feReg32
			elseifidn stSizeG$, <REAL4>
				SetVR <@SubStr(<fline>, 5, isto-6)>, fcr4
			elseifidn stSizeG$, <REAL8>
				SetVR <@SubStr(<fline>, 5, isto-6)>, fcr8
			elseifidn stSizeG$, <REAL10>
				SetVR <@SubStr(<fline>, 5, isto-6)>, fcr10
			else
				if stSizeG lt DWORD
						tmp$ equ feReg32
				elseif stLastType eq MbQword
						tmp$ CATSTR <Qword ptr [>, feReg32, <]>
				else
						if usedeb
							tmp$ CATSTR <** line >, %@Line, <: struct >, stSizeG$, < **>
							% echo tmp$
							; .err
						endif
						tmp$ CATSTR <[>, feReg32, <.>, stSizeG$, <]>
				endif
				; % echo tmp$
				SetVR <@SubStr(<fline>, 5, isto-6)>, tmp$
			endif
			fEach$ SUBSTR <fline>, 5, isto-6
			ctEach equ ctVar
			; % echo current: fEach$
			; fOa = opattr fEach$
			fArr=@SubStr(<fline>, isto+3)
			ctStep equ <1>
			isstep=0
			ctStart equ <0 >
			if fArr ge 0
					mov eax, [MbArrTable+4*fArr]
				mov eax, [eax]	; #elements of string array (last el=eax-1)
			else
					mov eax, [NumArrTable+4*fArr]
					mov eax, [eax-8]
				endif
				dec eax
			ctEnd equ <eax>
  else
	iseq INSTR <fline>, <=>
	isto INSTR <fline>, <To >
	ife isto
		isto INSTR <fline>, <TO >
		ife isto
			isto INSTR <fline>, <To>
		endif
		ife isto
			isto INSTR <fline>, <a >	; FR, IT
		endif
		ife isto
			% echo @CatStr(<## For...Next: no To in line >, %@Line, < ##>)
			.err
		endif
	endif
	ctVar	SUBSTR <fline>, 1, iseq-1
	ctStart	SUBSTR <fline>, iseq+1, isto-iseq-1
	isstep INSTR isto, <fline>, <Step>
	if isstep
		ctStep SUBSTR <fline>, isstep+5
		ctEnd SUBSTR <fline>, isto+2, isstep-isto-2
	else
		ctStep equ <1>
		ctEnd SUBSTR <fline>, isto+2
	endif
  endif
  ArgType=(opattr ctVar) AND 127
  cvType=MbDword
  if ArgType
	cvType=ChkNum(ctVar)
  endif
;   tmp$ CATSTR <cVar=>, ctVar, <, t=>, %ArgType, <, cStart=>, ctStart, <, cEnd=>, ctEnd, <, cType=>, %cvType
;   % echo tmp$
  if cvType gt MbDword
 	ffree st(7)
	is INSTR ctStart, <.>
	if is
		fld FP10(ctStart)
	else
		fld ctStart
	endif
	if cvType eq MbReal10
		ffree st(7)
		fld st
		fstp ctVar
	else
		fst ctVar
	endif
	is INSTR ctEnd, <.>
	if is
		fld FP10(ctEnd)
		fsubr
	else
		fsubr ctEnd
	endif
	is INSTR ctStep, <.>
	if is
		.DATA
		ctStepF REAL10 ctStep
		ctStep CATSTR <f+>, <ctStepF>
		.CODE
		fld ctStepF
		fdiv
	else
		fdiv ctStep
		ctStep CATSTR <f+>, <ctStep>
	endif
	fistp MbForCounters[bLoopCtFor*4]
  else
  if (ArgType ne 48) and (ArgType ne 34)	;; not a register or SetGlobals var
	% ifndef ctVar
	.DATA?
		ctVar	dd ?
	.CODE
	endif
  endif
  is INSTR ctEnd, <]>	; sg?
  if is lt 2
	is=2
  endif
  ctSm INSTR is, ctEnd, <->
  ctSp INSTR is, ctEnd, <+>
  if ctSp gt 2
	vtE$ SUBSTR ctEnd, 1, ctSp-1			;; x plus
	otE$ SUBSTR ctEnd, ctSp+1			;; if +1 To, there is a blank
;	echo PLUS
  elseif ctSm gt 2
	vtE$ SUBSTR ctEnd, 1, ctSm-1		;; x minus
	otE$ SUBSTR ctEnd, ctSm+1			;; if -1 To, there is a blank
;	echo MINUS
  else
  	vtE$ equ <ctEnd>
  endif
  atVt = (opattr vtE$) AND 127
  tregpush = 0
  if atVt eq atRegister
	tmpReg equ vtE$		;; we take the ctEnd register as is
	ifdef otE$
		tregpush = 1		;; offset, we need to push a tmp register
	endif
  else
	tmpReg equ eax
	tregpush = 1			;; not a register, we need one
  endif
  if tregpush
	push tmpReg
	ifdifi tmpReg, vtE$
		mov tmpReg, vtE$
	endif
  endif
  ifdef otE$
  	ifidn otE$, <1>
   		if ctSp
  			inc tmpReg
  		else
  			dec tmpReg
  		endif
  	else
   		if ctSp
  			add tmpReg, otE$
  		else
  			sub tmpReg, otE$
  		endif
  	endif
  endif
  mov MbForCounters[bLoopCtFor*4], tmpReg
  if tregpush
	pop tmpReg
  endif
  ctSm INSTR 2, ctStart, <->
  ctSp INSTR 2, ctStart, <+>
  if ctSp
	vtS$ SUBSTR ctStart, 1, ctSp-1	;; x plus
	otS$ SUBSTR ctStart, ctSp+1		;; if +1 To, there is a blank
  elseif ctSm
	vtS$ SUBSTR ctStart, 1, ctSm-1	;; x minus
	otS$ SUBSTR ctStart, ctSm+1		;; if -1 To, there is a blank
  else
  	vtS$ equ <ctStart>
  endif
  atVt = (opattr vtS$) AND 127
  if atVt eq atRegister
	tmpReg equ vtS$		;; we take the ctStart register as is
	ifdef otS$
		tregpush = 1		;; offset, we need to push a tmp register
	endif
  else
	tmpReg equ eax
	tregpush = 1			;; not a register, we need one
  endif
  if tregpush
	push tmpReg
	ifdifi tmpReg, vtS$
		if atVt eq atImmediate
			ife vtS$
				xor tmpReg, tmpReg
			elseif vtS$ eq -1
				or tmpReg, -1
			elseif (vtS$ le 127) and (vtS$ ge -128)
				push vtS$
				pop tmpReg
			else
				mov tmpReg, vtS$
			endif
		else
			mov tmpReg, vtS$
		endif
	endif
  endif
  ifdef otS$
  	ifidn otS$, <1>
   		if ctSp
  			inc tmpReg
  		else
  			dec tmpReg
  		endif
  	else
   		if ctSp
  			add tmpReg, otS$
  		else
  			sub tmpReg, otS$
  		endif
  	endif
  endif
  sub MbForCounters[bLoopCtFor*4], tmpReg
  if isstep	; calc necessary loops
	ffree st(7)
	fild MbForCounters[bLoopCtFor*4]
	push ctStep
	fidiv stack
	fistp MbForCounters[bLoopCtFor*4]
	lea esp, [esp+DWORD]	; keep flag
  endif
  mov ctVar, tmpReg	; initial value to e.g. ct
  if tregpush
	pop tmpReg
  endif
  endif
  ctVar4N CATSTR <ctVarL>, %bLoopCtFor	;; ctVarL0
  % ctVar4N equ <ctVar>
  ctVar4E CATSTR <ctVarE>, %bLoopCtFor	;; ctVarE0
  % ctVar4E equ <ctEnd>
  ctVar4S CATSTR <ctVarS>, %bLoopCtFor	;; ctVarS0
  if cvType gt MbDword
	% ctVar4S equ <ctStep>	; OffSet
  else
	% ctVar4S equ <ctStep>
  endif
  MbForLoop CATSTR <MbForLabel>, %bLoopCtFor
  MbForBreak CATSTR <MbForBreak>, %bLoopCtFor
  if MbForReject	;; don't loop if counter negative
	if cvType eq MbDword
		if ctStep gt 0
			js MbForBreak
		else
			jg MbForBreak
		endif
	else
		cmp MbForCounters[bLoopCtFor*4], 0
		js MbForBreak
	endif
  endif
  align 4
  MbForLoop:
  ifdef fArr
	if fArr ge 0
		push ctVar
		push fArr
		call MbArrayGet
		feR32Warn=@Line
	else
		imul eax, ctVar, stSizeG
		add eax, [NumArrTable+4*fArr]
		if stLastType eq MbReal4 or stLastType eq MbReal8 or stLastType eq MbReal10
			fld stSizeG$ ptr [eax]
			fstp fEach$
			exitm
		elseif stSizeG eq DWORD
			mov eax, [eax]
		elseif stSizeG eq WORD
			movsx feReg32, word ptr [eax]
			feR32Warn=@Line
			exitm
		elseif stSizeG eq BYTE
			movsx feReg32, byte ptr [eax]
			feR32Warn=@Line
			exitm
		else
			xchg eax, feReg32
			feR32Warn=@Line
			exitm	; no action here, eax is pointer to struct element
		endif
	endif
	ifidni < eax>, fEach$
		echo using eax in for...each??
	endif
	; % echo ______ [fEach$] ____
	ifdif fEach$, feReg32
		xchg eax, fEach$
	else
		xchg eax, feReg32
	endif
	feR32Warn=@Line
  endif
ENDM
MbNext macro ctVar1
LOCAL tmp$, is, bLoopCtNext, ctVar4N, ctVar4E, ctVar4S
  if (feR32Warn gt 0) and usedeb
	if usedeb
		tmp$ CATSTR <** for..each in line >, %feR32Warn, < uses >, feReg32 , < **>
		% echo tmp$
	endif
  endif
  feR32Warn=0
  is INSTR MbNext$, <#>
  bLoopCtNext SUBSTR MbNext$, 1, is-1
  MbNext$ SUBSTR MbNext$, is+1
  ctVar4N CATSTR <ctVarL>, %bLoopCtNext
  ctVar4E CATSTR <ctVarE>, %bLoopCtNext
  ctVar4S CATSTR <ctVarS>, %bLoopCtNext
  ifnb <ctVar1>
	% ifdif <ctVar4N>, <ctVar1>
		echo
		echo Next:
		tmp$ CATSTR <Expected   var = !<>, <ctVar4N>, <!>>
		% echo tmp$
		tmp$ CATSTR <Unexpected var = !<>, <ctVar1>, <!>>
		% echo tmp$
		echo
		.err
	endif
  endif
  ifidn ctVar4S, <1>
	inc ctVar4N
  else
	is INSTR ctVar4S, <f+>
	if is
		ctVar4S SUBSTR ctVar4S, 3
		fld ctVar4S
		fld ctVar4N
		fadd
		fstp ctVar4N
	else
		oa = opattr ctVar4S
		if (oa eq atImmediate) or (oa eq atRegister)
			add ctVar4N, ctVar4S
		elseif 0	; float
		else
			tmp$ CATSTR <## illegal Step in line >, %@Line, < ##>
			.err tmp$
		endif
	endif
  endif
  MbForLoop CATSTR <MbForLabel>, %bLoopCtNext
  if MbFnCount
	inc MbFNC
  endif
  dec MbForCounters[bLoopCtNext*4]
  jge MbForLoop
  MbForBreak CATSTR <MbForBreak>, %bLoopCtNext
  MbForBreak:
  .Until 1
  if MbFnCount
	MbFnCount=0
	and MbFNC, 0
  endif
ENDM			; ---- end for_next ---
cStyleW$ MACRO arg:=<>
  csWide = 1
  EXITM <cStyle$(arg)>
ENDM

csWide = 0
cStyle$ MACRO arg:=<>	;; thanks to qWord for improving this macro
LOCAL PP, quot, c$, parseLen, P$, Esc, QuotState, cDest$, cstString, argWide, tmp$
  P$ equ <arg>	;; string to parse
  cDest$ equ <arg>
  Esc=0			;; 1 = escape sequence
  QuotState=0		;; 1 = currently writing to quoted text
  quot SUBSTR P$, 1, 1
  hasQu=0
  ifidn quot, <">
	hasQu = 1
  elseifidn quot, <'>
	hasQu = 1
  endif
  if @InStr(1, <arg>, <\>)
	ife hasQu
		.err <invalid string>
	endif
	cDest$ equ <>
	parseLen SIZESTR P$
	PP=2			; we ignore
	REPEAT parseLen-2	; the quotes
	c$ SUBSTR P$, PP, 1
	isN INSTR c$, <[ebx>	; for..next or setglobals n
	ife isN
		ifidni c$, <n>
			isN=1
		endif
	endif
	ife Esc
		ifidn c$, <\>
			Esc = 1
		else
			if QuotState
				cDest$ CATSTR cDest$, c$		; append a char
			else
				cDest$ CATSTR cDest$, <,>, quot, c$
				QuotState = 1
			endif
		endif
	else
		if isN	; <n>
			if QuotState
				cDest$ CATSTR cDest$, quot, <, 13,10>
				QuotState = 0
			else
				cDest$ CATSTR cDest$, <, 13,10>
			endif
		elseifidn c$, <t>
			if QuotState
				cDest$ CATSTR cDest$, quot, <,9>
				QuotState = 0
			else
				cDest$ CATSTR cDest$, <,9>
			endif
		elseifidn c$, <0>
			if QuotState
				cDest$ CATSTR cDest$, quot, <,0>
				QuotState = 0
			else
				cDest$ CATSTR cDest$, <,0>
			endif
		elseifidn c$, <\>
			if QuotState
				cDest$ CATSTR cDest$, c$
			else
				cDest$ CATSTR cDest$, <,>, quot, c$
				QuotState = 1
			endif
		else
				tmp$ CATSTR <## line >, %@Line, <: invalid escape sequence \>, c$, < in >, <arg>, < ##>
			% echo tmp$
			.err
		endif
		Esc = 0
	endif
	PP=PP+1
	ENDM
	if QuotState
		cDest$ CATSTR cDest$, quot
	endif
	parseLen SIZESTR cDest$
	if parseLen GT 1                       ; remove leading comma
		ifidn @SubStr(<%cDest$>, 1, 1), <,>
			cDest$ SUBSTR cDest$, 2
		endif
	endif
	.DATA
	cstString db cDest$, 0	; create the string
	if csWide
		csWide = 0	; clear Unicode flag
		.DATA?
		align 2
		argWide dw SIZEOF cstString dup(?)
		.CODE
		push edx
		push offset cstString
		push offset argWide
		call wDataP
		pop edx
		EXITM <OffSet argWide>	; OffSet indicates wChr$
	endif
	.CODE
	EXITM <offset cstString>
  else
	if csWide
		csWide = 0	; clear Unicode flag
		raWide = 1	; trigger repargW
	endif
	EXITM repargA(cDest$)	; use standard macro
  endif
ENDM

Space$ MACRO numsp, src
  ifb <src>
	EXITM String$(numsp, 32)
  else
	push ecx
	push edi
 	push numsp
	push -2
	push repargA(src)
	call MbBufferGet
	push eax
	xchg eax, edi
	call MbCopy	; invoke MbCopy, eax, src, -2
	xchg eax, edi
	pop ecx
	sub eax, edi	; eax = - (bytes copied)
	add ecx, eax	; num-bufferstart
	.if !Sign?
		mov al, 32
		rep stosb
	.endif
	push 1
	push edi
	call MbBufferFix
	pop edi
	pop ecx
	EXITM emArr$
  endif
ENDM

String$ MACRO ct:REQ, src:=<0>
LOCAL nu1st, hasq, c1$
  PushPlusMinus ct
  c1$ SUBSTR <src>, 1, 1	;; here the <> are needed
  ifidn c1$, <">			;; if 1st char = ", we assume this is the source
	hasq = 1
  elseifidn c1$, <'>			;; same for apostrophe
	hasq = 1
  else
	hasq = 0
  endif
  if hasq
	.DATA
		nu1st	db src, 0
	.CODE
	push offset nu1st
  elseifidn <0>, <src>
	push src
  else
	if ((opattr(src)) AND 127) eq 36		;; immediate
		.DATA
			nu1st	db src, 0
		.CODE
		push offset nu1st
	else
		push src
	endif
  endif
  call StringFill			;; src, ct
  EXITM <( eAx)>
ENDM
MemSet MACRO dest0, pat0, bytect
LOCAL dest, pat, patB, oa, tmp$
  ifidni <dest0>, <ecx>
	.err <## MemSet: ecx not allowed ##>
  elseifdifi <dest0>, <eax>
	dest equ <edx>
	pat equ <eax>
	patB equ <al>
  else
	dest equ <eax>
	pat equ <edx>
	patB equ <dl>
  endif
  oa = (opattr pat0) AND 127
  if (oa eq atImmediate) or (oa eq atRegister)
	tmp$ CATSTR <pat0>, <  >
	tmp$ SUBSTR tmp$, 2, 2
	ifdifi pat, <pat0>
		ifidni tmp$, <L >
			movzx pat, pat0
			imul pat, 1010101h
		elseifdifi tmp$, <mm>
			mov pat, pat0
		endif
	endif
	ifdifi dest, <dest0>
		mov dest, dest0
	endif
	if oa eq atImmediate
		if pat0 le 255
			imul pat, 1010101h
		elseif pat0 le 65535
			imul pat, 10001h
		endif
	endif
	ifdifi tmp$, <mm>
		movd xmm0, pat
		pshufd xmm0, xmm0, 0
	else
		movd pat, xmm0
	endif
	push ecx
	push pat
	lea ecx, [dest+bytect-16]
	align 4
	.Repeat
		movups oword ptr [dest], xmm0
		add dest, 16
	.Until dest>ecx
	pop pat
	sub ecx, dest
	neg ecx
	.While ecx<16
		mov [dest], patB
		ror pat, 8
		inc dest
		inc ecx
	.Endw
	pop ecx
  else
	.err @CatStr(<## line >, %@Line, <: MemSet wants a register or an immediate value like "x" or "abcd" ##>)
  endif
ENDM
MbPMC STRUCT
 cbSize 	       	dd ?
 PageFaultCount	dd ?
 PeakWorkingSetSize	dd ?
 WorkingSetSize	dd ?
 QuotaPeakPagedPoolUsage	dd ?
 QuotaPagedPoolUsage	dd ?
 QuotaPeakNonPagedPoolUsage	dd ?
 QuotaNonPagedPoolUsage	dd ?
 PagefileUsage	dd ?
 PeakPagefileUsage	dd ?
MbPMC ENDS
msUse=1
msUnit=10
msTrigger=4096
MemState MACRO msArg:=<WorkingSetSize>, msModes:VARARG ; msArg: Str$() format string or PROCESS_MEMORY_COUNTERS element, msModes: abs del always
Local msRel, msAbs, msAlways, msNew, msOld, c1$
  c1$ SUBSTR <msArg>, 1, 1
  ifb <msModes>
	msRel=1
	msAbs=0
	msAlways=0
  else
	msRel INSTR <msModes>, <del>
	msAbs INSTR <msModes>, <abs>
	msAlways INSTR <msModes>, <alw>
  endif
  if msUse
  ifndef msPMC
	.DATA?
	msPMC MbPMC 2 dup(<>)	; PROCESS_MEMORY_COUNTERS <>
	.CODE
	ifndef GetModuleFileNameEx
		uselib psapi
	endif
  endif
  ifidn c1$, <">
	pushad
  else
	push esi
	push ecx
  endif
  mov esi, offset msPMC
  msNew equ [esi.MbPMC]
  msOld equ [esi.MbPMC+MbPMC]
  invoke GetProcessMemoryInfo, rv(GetCurrentProcess), esi, MbPMC
  ifidn c1$, <">
	mov ecx, msNew.WorkingSetSize	; default
	push ecx
	mov eax, ecx
	if msUnit
		sar ecx, msUnit	; default is 10, kB
	endif
	sub eax, msOld.WorkingSetSize	; get delta
	cmp msOld.WorkingSetSize, 0
	pop msOld.WorkingSetSize
  else
	mov ecx, msNew.msArg
	push ecx
	mov eax, ecx
	sub eax, msOld.msArg
	cmp msOld.msArg, 0
	pop msOld.msArg
  endif
  .if !Zero?
	ife msAlways
	  .if signed eax<=-msTrigger || signed eax>=msTrigger
	endif
		if msUnit
			sar eax, msUnit	; default is 10, kB
		endif
		ifidn c1$, <">	; something to print
			if msAbs
				if msRel
				  push eax
				  Print Str$(msArg, ecx)
				  pop eax
				  PrintLine Str$(eax)
				else
				  Print Str$(msArg, ecx)
				endif
			else
				Print Str$(msArg, eax)		; delta only
			endif
		endif
	ife msAlways
	  .endif
	endif
  .endif
  if msAbs
	xchg eax, ecx
  endif
  ifidn c1$, <">
	popad
	EXITM <>
  else
	pop ecx
	pop esi
	EXITM <eax>
  endif
  elseifdif c1$, <">
	EXITM <-127>
  endif
ENDM
staOut STRUCT
  minCol	dd ?
  maxCol	dd ?	; max # columns found
  minColLine	dd ?
  maxColLine	dd ?
  ctTxt	dd ?
  ctDec	dd ?
  ctHex	dd ?
  ctBin	dd ?
  ctLines	dd ?	; overall #lines
  numCols	dd ?	; max #numerical columns found
  res2	dd ?
  res3	dd ?
staOut ENDS

if 1		; flags for text to numeric array - check original in MbTxt2Dw
  staHasText=	1	; if set, embedded text, eg. 123 some name 456, will be skipped; if not set, the algo aborts when hitting text
  staHasDollars=	2	; if set, $120.1 will be interpreted correctly, but hex $12ab will fail
  staHasCommas=	4	; if set, 1,234,567 will be interpreted correctly, but comma-separated text will fail
endif
StringToArray MACRO src, dest, flags:=<0>	; StringToArray Win$(hEdit), Edit$()
LOCAL isL, isR, strL, strR, oa, tmp$	; s2a "Start"+CrLf$+Win$(hEdit)+"End", Edit$() is possible but CrLf$ or Lf$ must "match"
  isL INSTR <dest>, <$(>
  if isL
	isR INSTR <dest>, <)>
	strL SUBSTR <dest>, 1, isL+1
	strR SUBSTR <dest>, isR
	% @CatStr(<Dim >, strL, <-123>, strR)
	void dest
  endif
  if stLastID ge 0
	ifidni <flags>, <linux>	; check for LF
		push 120
	elseifidni <flags>, <unix>
		push 120
	elseifidni <flags>, <tab>	; tab-delimited
		push -120
	elseifidni <flags>, <csv>	; comma-separated values
		push -121
	else
		push flags
	endif
  endif
  ifidn <src>, <( eAx)>
	call MbGetSlotPointer
	push 0
	push [edx]	; data src
  else
	isL INSTR <src>, <Use_>
	isR INSTR <src>, <MbC:>
	ife isR
		isR INSTR <src>, <">
		ife isR
			isR INSTR <src>, <'>
		endif
	endif	
	if isL or isR
		push Cat$(src)	; e.g. StringToArray "JJ downloads:"+Lf$+FileRead$("http://www.japheth.de/Download/JWasm"), jw$()
	else
		isR INSTR <src>, <res:>
		if isR
			tmp$ SUBSTR <src>, 5
			oa=atImmediate
		else
			tmp$ equ <src>
			oa = (opattr src) AND 127	; JWasm doesn't like iff opattr(scr)
		endif
		if oa eq atImmediate
			invoke FindResource, 0, tmp$, RT_RCDATA
			if usedeb
					test eax, eax
					ifidni SubSys, <console>
						.if Zero?
							Inkey Str$("## line %i: ", @Line), Str$("Resource %i not found ##", tmp$)
							Exit
							MbExit=0
						.endif
					else
						ExternDef MbError3:NEAR
						je MbError3
					endif
			endif
			push rv(LoadResource, 0, eax)
		else
			push src
		endif
	endif
  endif
  push stLastID
  if stLastID lt 0
	push stLastType or 256*stSizeG	; arrSize
	push flags	; parseMode
	MbTxt2Dw PROTO :DWORD, :DWORD, :DWORD, :DWORD
	call MbTxt2Dw	; numerical array, returns ptr to staOut struct
  else
	push 127	; special filenum
	call RecallP	; string array
  endif
ENDM
Join$ MACRO arr, dest0
LOCAL ediJ, esiJ, dest, hasq
  esiJ equ <esi>
  ediJ equ <edi>
  dest equ <MbCat$>
  hasq=0
  ifnb <dest0>
	hasq INSTR <dest0>, <">
  	ife hasq
		dest equ <dest0>
		ifidni dest, <edi>
			ediJ equ <ebx>
		elseifidni dest, <esi>
			esiJ equ <ebx>
		elseifidni dest, <ecx>
			echo ## ecx not allowed as destination ##
			.err
		endif
	endif
  endif
  oa = (opattr arr) AND 127
  if (opattr arr) ne atImmediate
	.err @CatStr(<## >, <arr>, < is not a string array ##>)
	EXITM <>
  endif
  push ecx
  push esiJ
  push ediJ
  mov esiJ, [MbArrTable+4*arr]
  mov ecx, [esiJ.StringArrHeader.numEL]
  dec ecx
  add esiJ, StringArrHeader-8
  push ecx
  push esiJ
  .Repeat
	add esiJ, 8
	mov eax, [esiJ+4]
	test eax, eax
	.if Sign?
		neg eax
	.endif
	add ediJ, eax
	inc ediJ
	inc ediJ
	dec ecx
  .Until Sign?
  mov ecx, dest
  Let ecx=New$(ediJ)
  mov ediJ, ecx		; ediJ is now dest
  pop esiJ
  pop ecx
  push ediJ
  .Repeat
	add esiJ, 8
	mov eax, [esiJ+4]
	test eax, eax
	.if Sign?
		neg eax
	.endif
	invoke MbCopy, ediJ, [esiJ], eax
	if hasq
		invoke MbCopy, eax, repargA(dest0), -2
		xchg eax, ediJ
	else
		mov word ptr [eax], 0A0Dh
		lea ediJ, [eax+2]
	endif
	dec ecx
  .Until Sign?
  if hasq
	sub ediJ, raSize
	and dword ptr [ediJ], 0 
  endif
  ifb <dest0>
	hasq=1
  endif
  if hasq
	pop ediJ	; MbCat$
	xchg eax, ediJ
	pop ediJ
	pop esiJ
	pop ecx
	EXITM <eax>
  else
	pop dest
	pop ediJ
	pop esiJ
	pop ecx
	EXITM <>
  endif
ENDM

Split$ MACRO src, delimiter, array
  StringToArray Replace$(src, delimiter, CrLf$), array
  EXITM <eax>
ENDM

Filter$ MACRO arr, sub$, incl:=<1>, mode:=<1>
  push edi
  push esi
  push ebx
  push ecx
  ifdifi <sub$>, <ebx>
	mov ebx, repargA(sub$)
  endif
  mov esi, MbArrTable[4*arr]
  mov eax, [esi.StringArrHeader.numEL]
  dec eax
  push eax
  xor ecx, ecx
  add esi, StringArrHeader	; put on #0
  mov edi, esi
  .Repeat
	if incl
	  .if Instr_(1, [esi], ebx, mode)	; include if match
	else
	  .if !Instr_(1, [esi], ebx, mode) && eax!=[esi+4] 	; exclude: don't include empty strings
	endif
		movlps xmm0, qword ptr [esi]
		movlps xmm1, qword ptr [edi+8*ecx]
		movlps qword ptr [edi+8*ecx], xmm0
		movlps qword ptr [esi], xmm1
		inc ecx
	.endif
	add esi, 8
	dec stack
  .Until Sign?
  push ecx		; set element
  push arr			; and last ID
  call MbArrayGet
  push 80000000h	; delete all above ecx
  call MbInsert
  xchg eax, ecx	; get count
  pop ecx
  pop ebx
  pop edi
  pop esi
  EXITM <eax>
ENDM

Lamp$ macro cycles:REQ, csize:REQ	; Usage: Print LAMP$(cycles, size), " LAMPs", 13, 10
	ffree ST(7)			;; free the stack for pushing
	mov eax, csize
	.if eax==0
		add eax, MinLampSize
	.endif
	push eax
	fild stack		;; move into ST (0)
	pop eax
	fsqrt
	push cycles
	fild stack		;; push cycles on FPU
	fmul ST, ST(1)		;; multiply with sqrt(size)
	fistp stack
	pop eax
	ifndef LampsBuffer
		.DATA?
LampsBuffer		dd 80 dup (?)
		.CODE
	endif
	invoke dwtoa, eax, addr LampsBuffer
EXITM <offset LampsBuffer>
ENDM

wData MACRO argWide:REQ, args:VARARG
LOCAL argByte
.DATA
  argByte	db args
.DATA?
align 2
  argWide	dw SIZEOF argByte dup(?)
.CODE
  push offset argByte
  push offset argWide
  call wDataP
ENDM

; *** string management ********
Bin$ MACRO dwArg:REQ, tgt:=<0>
  ifdifi <dwArg>, <eax>			;; check to avoid a mov eax, eax
	mov eax, dwArg			;; eax passes value to translate
  endif
  if @SizeStr(tgt) gt 1
	mov edx, tgt			;; dest buffer - if 0, use Dw2BinBuffer
  else
	mov edx, offset Dw2BinBuffer
  endif
  call MbBinP
  ifidni <tgt>, <f>				;; option f, formatted
	mov word ptr 32[edx], 13*256+10
  endif
  EXITM <edx>
ENDM

Hex$ MACRO src0:REQ
LOCAL is, src
  src equ <src0>		; hack
  is INSTR 1, src, <ST>
  if is eq 1
	is=MbReal10
  else
	is INSTR src, <f:>
	if is
		% echo ## f: meaningless in src ##
		src SUBSTR src, 3
	endif
	is=ChkNum(src)
  endif
  if is eq MbReal10
	ffree st(7)
	fld src
	push 10  	; REAL10, ST(n)
	push eax	; ignored
  elseif is le MbReal4
	is INSTR aPass$, <p:>	; bp:, wp:
	if is eq 2
		is INSTR aPass$, <bp:>
		if is
			push BYTE
		else
			push WORD
		endif
		movzx eax, src	; byte or word
		push eax
	else
		push 4
		push src	; dword
	endif
  elseif (is eq MbReal8) or (is eq MbQword)
	push 8
	lea eax, src
	push eax	; addr MyReal8
  else
	push 16
	ifndef MbHex16
		.DATA?
		MbHex16	dq ?, ?	; xmm full size
		.CODE
	endif
	mov eax, offset MbHex16
	movups oword ptr [eax], src
	push eax
  endif
  MbHexP	PROTO :DWORD, :DWORD
  call MbHexP
  EXITM emArr$	; make sure Let reads it properly
ENDM

FilesDiffer MACRO FileA:REQ, FileB:REQ, casemode:=<0>	; dword size files only!
LOCAL is, tmp$
  MbFileCmp	PROTO: DWORD, :DWORD, :DWORD
  ifidni <FileA>, <FileB>
	is INSTR <FileA>, <">	; opattr of "string" yields 0 with ml but 36 with JWasm
	ife is
		tmp$ CATSTR <## line >, %@Line, <: two macros not allowed, please split ##>
		% echo tmp$
		.err
	endif
  endif
  invoke MbFileCmp, repargA(FileA), repargA(FileB), casemode
  EXITM <eax>
ENDM
wStringsDiffer MACRO s1$, s2$, mode:=<0>
  EXITM StringsDiffer(s1$, s2$, mode or 16)
ENDM
StringsDiffer MACRO StrA:REQ, StrB:REQ, casemode:=<0>
LOCAL is
  ifidni <StrA>, <StrB>
	is INSTR <StrA>, <">	; opattr of "string" yields 0 with ml but 36 with JWasm
	ife is
		% echo @CatStr(<## line >, %@Line, <: two macros not allowed, please split ##>)
		.err
	endif
  endif
  MbStrCmp PROTO: DWORD, :DWORD, :DWORD
  invoke MbStrCmp, repargA(StrA), repargA(StrB), casemode
  EXITM <eax>
ENDM
Scramble MACRO arrID	; scr My$() - little helper to test sorts
  push esi
  push edi
  push ecx
  mov esi, MbArrTable[4*arrID]
  mov edi, [esi.StringArrHeader.numEL]
  dec edi
  add esi, StringArrHeader
  xor ecx, ecx
  .Repeat
	inc ecx	; skip header row
	movlps xmm0, qword ptr [esi+8*ecx]
	inc Rand(edi)	; don't use header row
	movlps xmm1, qword ptr [esi+8*eax]
	movlps qword ptr [esi+8*ecx], xmm1
	movlps qword ptr [esi+8*eax], xmm0
  .Until ecx>=edi
  xchg eax, edi	; ret #el
  pop ecx
  pop edi
  pop esi
ENDM
QSortMode MACRO csx:=<1>, slsx:=<1>, keys	; casemode, skipmode, index array
LOCAL qsm, is, tmp$
  qsm=0
  ifidni <csx>, <cis>
	qsm=1	; case-insensitive
  elseifidni <csx>, <1>
	qsm=1
  endif
  ifidni <slsx>, <sls>	; skip leading spaces
	qsm=qsm or 4
  elseifidni <slsx>, <1>
	qsm=qsm or 4
  endif
  MbQsID=0		; default for Ins+Del
  ifnb <keys>
	qsm=qsm or 4	; force sls
	if (opattr keys) ne atImmediate
		MbQsID=-MbArrCtSt
		is INSTR <keys>, <()>
		tmp$ CATSTR <Dim >, @SubStr(<keys>, 1, is), <-123>, <) As DWORD>
		tmp$
	elseife stCtG
		tmp$ CATSTR <## line >, %@Line, <: needs Dim xy>
		% echo tmp$() with empty brackets ##
		.err
	else
		MbQsID=stLastID
	endif
	qsm=qsm+256*MbQsID
  endif
  ExternDef QsMode:WORD
  mov QsMode, qsm		; set cmpMode
ENDM
@qsJ MACRO ctJ	; helper for QSxx
LOCAL is, qsCt, toEdx, tmp$
  is INSTR <ctJ>, <:>
  if is
	toEdx SUBSTR <ctJ>, 1, is-1
	if is ge @SizeStr(<ctJ>)
		qsCt equ 7fffffffh
	else
		qsCt SUBSTR <ctJ>, is+1
	endif
	if (opattr qsCt) eq atImmediate
		ife qsCt
			push -7fffffh
		else
			push -qsCt
		endif
	else
		push qsCt
		neg stack
	endif
	mov edx, @SubStr(<ctJ>, 1, is-1)
  elseifidn <ctJ>, <1>
	tmp$ CATSTR <## line >, %@Line, <: you can't sort a single element ##>
	% echo tmp$
	.err
  else
	push ctJ
  endif
ENDM
MbQS$ equ MbQSortP
QSort MACRO ArrID, ct:=<0>, col, skipH	; string sort uses stable mergesort
  @qsJ ct
  ifb <col>
	push ArrID
  elseif (opattr col) eq atImmediate
	ifidn <0>, <skipH>
		push ArrID or (col shl 17)
	else
		push ArrID or (col shl 17) or 10000h
	endif
  else
	mov eax, col
	shl eax, 17
	ifidn <0>, <skipH>
		or eax, ArrID
	else
		or eax, ArrID or 10000h
	endif
	push eax
  endif
  call MbQS$
ENDM

QSortDesc MACRO ArrID, ct:=<0>, col, skipH
  @qsJ ct
  ifb <col>
	push -ArrID
  elseif (opattr col) eq atImmediate
	ifidn <0>, <skipH>
		push -(ArrID or (col shl 17))
	else
		push -(ArrID or (col shl 17) or 10000h)
	endif
  else
	mov eax, col
	shl eax, 17
	ifidn <0>, <skipH>
		or eax, ArrID
	else
		or eax, ArrID or 10000h
	endif
	neg eax
	push eax
  endif
  call MbQS$
ENDM
ClearLocals MACRO args	; use below last LOCAL
Local is, tmp$
  is INSTR @CurSeg, <TEXT>
  ife is
	tmp$ CATSTR <## line >, %@Line, <: put .code before the proc ##>
	% echo tmp$
  endif
  call ClearLocalsP
  ifnb <args>
	.err <## "uses" after proc - delete matching PopUses, too ##>
  endif
ENDM

PushUses macro args:REQ	; PU or CLV may work together with PopUses
LOCAL isL, isR, prPush$
  CLV = 1
  CLV_list equ <>
  .if 1
	isL INSTR <args>, <uses>
	if isL
		isL=isL+4
	endif
	isL=isL+1
	While isL
		isR INSTR isL, <args>, < >
		if isR
			prPush$ SUBSTR  <args>, isL, isR-isL
		  	isL=isR+1
			CLV = CLV+1
		else
			prPush$ SUBSTR  <args>, isL
			isL=0
		endif
		push prPush$
	  	CLV_list CATSTR prPush$, <@ >, CLV_list
	  ENDM
ENDM
PopUses macro
LOCAL isL, popArg
  isL=0
  While CLV
	CLV_list SUBSTR CLV_list, isL+1
	isL INSTR 2, CLV_list, <@>
  	popArg SUBSTR CLV_list, 1, isL-1
  	pop popArg
  	CLV=CLV-1
  Endm
  .endif
ENDM
MbSbCt=0
StackBuffer MACRO bytes, zMode	; mov locPtr, sb(50000, nz)
  ifnb <bytes>
    .if 1
    	MbSbCt=MbSbCt+1
	ifdifi <bytes>, <eax>
	    mov eax, bytes
	endif
    	ifb <zMode>
		MbStackB PROTO
		call MbStackB
  	elseifidni <zMode>, <nz>
		mov edx, esp	; save current stack pointer
		push edi
		mov edi, esp
		sub edi, eax
		sub edi, 3	; room for zero-dword
		and edi, -64	; aligns buffer to a cache line
		and dword ptr [edi+eax-2], 0	; buffer end +/-2 zeroed
		.repeat
				push eax	; tickle the guard page - limit might be 4k lower now
				ASSUME FS:Nothing
				mov esp, fs:[8]
				ASSUME FS:ERROR
		.until edi>=esp	; loop until we've got enough
		and dword ptr [edi], 0	; buffer start zeroed
		xchg eax, edi	; retval for macro
		mov esp, eax	; new stack
		mov edi, [edx-4]	; restore edi
		push edx	; save old stack pointer
  	else
  		.err <## unknown option &zMode ##>
		ifdifi <bytes>, <eax>
		    mov eax, bytes
		endif
	endif
	EXITM <eax>
  else
    While MbSbCt
	MbSbCt=MbSbCt-1
	pop esp			; no arg = free buffer before ret
    .endif
    ENDM
  endif
ENDM

MbLang equ tbs0.language	; ex MbFlags[44]
wLg$ MACRO args:VARARG
  EXITM wRec$(Lg$(args))
ENDM
Lg$ MACRO id$, forceLG
LOCAL is, tmp$, pat$
  MbGetLG PROTO
  ExternDef tbs0:TBarSUB
  is INSTR <id$>, <:>
  if is gt 4
	tmp$ SUBSTR <id$>, 1, 4
	ifidni tmp$, <file>
		Recall repargA(@SubStr(<id$>, is+1)), LgTb$(), tab
	elseifidni tmp$, <resi>
		UnzipInit @SubStr(<id$>, is+1)
		StringToArray UnzipFile(0), LgTb$(), tab
		UnzipExit
	elseifidni tmp$, <lang>
		push ecx
		tmp$ SUBSTR <id$>, is+1
		if opattr tmp$
			mov eax, [tmp$]
			push eax
		else
			if @InStr(1, <id$>, <Use_mov>)
				void Cat$(tmp$)
				push [eax]
			else
				tmp$ CATSTR <">, @SubStr(<id$>, is+2, 1), @SubStr(<id$>, is+1, 1), <">
				pushd tmp$
			endif
		endif
		xor ecx, ecx
		.Repeat
			inc ecx
			void LgTb$(0, ecx)
			movzx edx, word ptr [eax]
		.Until dx==word ptr [esp] || ecx>127
		mov MbLang, ecx
		pop edx
		pop ecx
		EXITM <>
	endif
  else
	oa = (opattr id$) AND 127
	if oa
		ifdifi <id$>, <eax>
			mov eax, id$
		endif
	else
		is SIZESTR <id$>
		if is eq 3
			pat$ CATSTR <">, <id$>, <	">
		else
			if is gt 4
				is INSTR <id$>, <$>
				if is ne 1
						tmp$ CATSTR < echo # Warning: only 4 chars relevant in line >, %@Line, < #>
						% echo tmp$
				endif
			endif
			pat$ CATSTR <">, @SubStr(<id$>, 1, 4), <">
		endif
		mov eax, pat$
	endif
	ifnb <forceLG>
		push dword ptr tbs0[8]
		PushXPM forceLG
		pop dword ptr tbs0[8]
		call MbGetLG
		pop dword ptr tbs0[8]
	else
		call MbGetLG
	endif
	exitm emArr$
  endif
ENDM
; ToolTips hEdit, "Type something", or ToolTips hButton, wRes$(123), etc
ttsEnd	= 0
ttNoInst	= 0
MbToolFlags	= TTS_NOPREFIX or TTS_BALLOON ; or TTS_ALWAYSTIP
MbToolExS	= WS_EX_TOPMOST
MbToolInst	equ <hInstance>
MbTTF	= TTF_SUBCLASS or TTF_IDISHWND ; or TTF_TRANSPARENT
ToolTips MACRO hTTC, lpText	; must be placed at the end of WM_CREATE handler
Local oa, tmp$
  ifidni <hTTC>, <end>
	ttsEnd=-1
	.endif
	pop esi
  else
	ife opattr MbToolInst
		ife ttNoInst
			ttNoInst=1
			% echo ## ToolTips: no MbToolInst found
		endif
		ifdef wc
			echo using  wc.hInstance  instead ##
			MbToolInst equ <wc.hInstance>
		endif
	endif
	ifb <lpText>
		ttStart=1
		.if 1
			TestInitCC
			push esi
			mov esi, offset MbTIS
			if (opattr hTTC) eq atImmediate
				MbToolFlags = hTTC
			endif
			ifidni MbToolInst, <eax>
				invoke GetModuleHandle, 0
			endif
			invoke CreateWindowEx, MbToolExS, Chr$("tooltips_class32"), 0,
			MbToolFlags, 0, 0, 0, 0, hWnd, 0, MbToolInst, 0
			mov [esi-4], eax		; store handle in hMbTIS
			m2m [esi.MbTOOLINFO.cbSize], sizeof MbTOOLINFO
			m2m [esi.MbTOOLINFO.uFlags], MbTTF
			m2m [esi.MbTOOLINFO.hwnd], hWnd
			ifidni MbToolInst, <eax>
				mov [esi.MbTOOLINFO.hinst], rv(GetModuleHandle, 0)
			else
				m2m [esi.MbTOOLINFO.hinst], MbToolInst
			endif
	else
		ife ttStart
			MbToolInst equ <eax>
			ToolTips
		endif
		oa = opattr lpText
		if oa eq atImmediate
			if lpText eq -1
				tmp$ equ <lpText>
			else
				tmp$ equ repargA(lpText)
			endif
		else
			tmp$ equ repargA(lpText)
		endif
		if ttsEnd lt 0	; change in some other handler
			push ecx
			push esi
			mov esi, offset MbTIS
			m2m [esi.MbTOOLINFO.uId], hTTC
			mov [esi.MbTOOLINFO.lpszText], tmp$
			ifidn <lpText>, <( EdX)>		; wRes$()
				invoke SendMessage, [esi-4], TTM_ADDTOOLW, 0, esi
			else
				invoke SendMessage, [esi-4], TTM_ADDTOOLA, 0, esi
			endif
			pop esi
			pop ecx
		elseifdif <lpText>, <0>
			m2m [esi.MbTOOLINFO.uId], hTTC
			mov [esi.MbTOOLINFO.lpszText], tmp$
			ifidn <lpText>, <( EdX)>		; wRes$()
				invoke SendMessage, [esi-4], TTM_ADDTOOLW, 0, esi
			else
				invoke SendMessage, [esi-4], TTM_ADDTOOLA, 0, esi
			endif
		endif
	endif
  endif
ENDM

Res$ MACRO id
  PushPlusMinus id
  call MbResString
  if MbUseErrLine
	.if word ptr [edx]=="?R"
			mov MbErrLine, @Line
		ExternDef MbErrAddLine:NEAR
		push 3
		jmp MbErrAddLine
	.endif
  endif
  EXITM <( Edx)>		;; lowercase x=Ansi
ENDM

wRes$ MACRO id, addBom
  ifidn <id>, <0>
	.err <## Res$ index must be non-zero>
  endif
  PushPlusMinus id
  ifidni <addBom>, <bom>
	or byte ptr [esp+3], 64
  endif
  neg stack
  call MbResString
  if MbUseErrLine
	.if dword ptr [edx]==003F0052h	; Unicode "?R"
			mov MbErrLine, @Line
		ExternDef MbErrAddLine:NEAR
		push 3
		jmp MbErrAddLine
	.endif
  endif
  EXITM <( EdX)>		;; uppercase x=Unicode
ENDM

CopyDataMac macro		; for use in a WM_COPYDATA handler, e.g. SetWin$ hEdit="Just received:"+CrLf$+CopyData$
  mov edx, lParam
  ifndef MbCopyData$
	.DATA?
	MbCopyData$	dd ?
	.CODE
  endif
  push [edx.COPYDATASTRUCT.lpData]
  pop MbCopyData$
  EXITM <MbCopyData$>
ENDM
CopyData$	textequ <CopyDataMac()>

SendData MACRO hWin, pString, thisWin:=<0>	; trashes xmm regs in Win64
LOCAL wTitle, ps$, buffer, is, sdlbl
	is INSTR <pString>, <)>
	if is ge 4
		ps$ SUBSTR <pString>, is-3, 3
		ifidni <hWin>, ps$
				tmp$ CATSTR <## line >, %@Line, <: handle=>, <hWin>, <, and 2nd macro returns >, <pString>, < ##>
				% echo tmp$
				.err
		endif
	endif
	ifndef cds
		.DATA?
		cds COPYDATASTRUCT <?>
		.CODE
	endif
	MbXms S2
	push ecx
	push edi
	mov ecx, repargA(pString)		; e.g. SendData "MyClient", Win$(hEdit)
	mov edi, offset cds
	wTitle equ repargA(hWin)
	oa = (opattr wTitle) AND 127
	if oa eq 38
		push WinByTitle(wTitle)		; got a string, so we still need the handle
	elseifidni <hWin>, <ecx>
		mov edx, stack[4]		; ecx was passed, so we need to retrieve the handle from stack
		push edx
	else
		push hWin		; this is already a handle
	endif
	mov [edi.COPYDATASTRUCT.lpData], ecx	; pString
	void Len(ecx)
	inc eax		; if omitted, Windows will forget to copy the zero delimiter
	mov [edi.COPYDATASTRUCT.cbData], eax	; length returned by WM_GETTEXT, plus one for delimiter
	pop eax		; the handle
	test eax, eax
	je sdlbl
	ifidni <eax>, <thisWin>
		echo eax not allowed as arg3
		.err
	endif
	invoke SendMessage, eax, WM_COPYDATA, thisWin, edi	; thisWin is optional, use for feedback
sdlbl:	pop edi
	pop ecx
	MbXmr
ENDM

SwcDDE=0
SendWordCommands MACRO strarg:=<init>
  push ecx
  push edi
  ife SwcDDE
	.DATA?
	pidInst	dd ?
	hItem	dd ?
	hTopic	dd ?
	hConv	dd ?
	hServer	dd ?
	.DATA
	txDdeSystem	db "System", 0
	txDdeWinWord	db "WinWord", 0
	.CODE
	.if !pidInst
		invoke DdeInitialize, offset pidInst, 0, APPCMD_CLIENTONLY, 0
		mov hTopic, rv(DdeCreateStringHandle, pidInst, offset txDdeSystem, 0)
		mov hServer, rv(DdeCreateStringHandle, pidInst, offset txDdeWinWord, 0)
	.endif
	mov hConv, rv(DdeConnect, pidInst, hServer, hTopic, 0)
	xchg eax, edi
	SwcDDE=1
  else
	mov edi, hConv
  endif
  ifidni <strarg>, <exit>
	invoke DdeDisconnect, edi
	invoke DdeFreeStringHandle, pidInst, hServer
	invoke DdeFreeStringHandle, pidInst, hTopic
	invoke DdeUninitialize, pidInst
	and pidInst, 0
  elseifdifi <strarg>, <init>
	.if edi
		ifdifi <strarg>, <esi>
				push esi
				if @InStr(1, <strarg>, <Use_Let>)
					mov esi, Cat$(strarg)
				elseifidni <strarg>, <edi>
					.err @CatStr(<## line >, %@Line, <: you cannot use edi in SendWordCommands, sorry ##>) 
				else
					mov esi, repargA(strarg)
				endif
		endif
		void Len(esi)
		inc eax	; string len including zero delimiter
		invoke DdeClientTransaction, esi, eax, edi, 0, 0, XTYP_EXECUTE, 10000, 0	; send WordBasic to MS Word
		ifdifi <strarg>, <esi>
			pop esi
		endif
	 .endif
  endif
  xchg eax, edi
  pop edi
  pop ecx
ENDM

; *** xls + DDE ***
MbXls$ equ <MbXls>
MbXls	PROTO :DWORD, :DWORD
if 0	; DDE rules
	Sequence:
	- connect with System	xlsConnect "System"
	- open a file	xlsCommand [open]
	- connect to sheet	needed for xlsWrite, xlsRead$()
	- read and write	xlsWrite, xlsRead$()
	- disconnect sheet	optional
	- close file	?? xlsCommand [close]
	- disconnect	no args means System
endif
MbDDE STRUCT
  pidInst	dd ?
  hConv	dd ?	; system
  hSheet	dd ?	; active workbook
  xTimeout	dd ?	; set in xlsConnect
  DdeReq$	dd ?
  hData	dd ?
  dBytes	dd ?
  ddeFlags	dd ?
  hItem	dd ?	; temporary handles
  hTopic	dd ?
  hServer	dd ?	; Excel
  hTemp	dd ?
  CF_xx	dd ?
  pCallback	dd ?
  hCallback	dd ?
  ddeCom	dd ?
  hotSz1	dd ?
  hotSz2	dd ?
  hotFmt	dd ?
  LastError	dd ?
  ofBuffer	db 512-80 dup(?)		; opened file
  cmdBuffer	db 512 dup(?)
MbDDE ENDS

xTimeout=10000	; set with flags
xsErrConsole=2	; 0=windows, 1=console, 2=auto
xsSys=0
; xsTopic=1
xsCmd=2
xsSysRead=3
xsOpen=4
xsConn=5
xsRead=6
xsWrite=7
xsDisc=8
xsClose=9
xsDiscAll=10
xsHotlink=11
xsHotlinkCb=12
xsHotlinkCbHc=13
xsCF=14
xsErr$=15
xlsConnect MACRO topic	; no args=System
  ifnb <topic>
	push xsConn
	push repargA(topic)	; "sheet"
	call MbXls$
  else
	.Repeat
		push xsSys
		push xTimeout*8+xsErrConsole
		call MbXls$
		.Break .if eax
		ExternDef xlsServer$:DWORD
		MsgBox 0, Cat$("Launch "+xlsServer$+", then click OK"), "xlsConnect:", MB_OKCANCEL or MB_ICONHAND or MB_TASKMODAL or MB_TOPMOST
		sub eax, IDCANCEL
	.Until Zero?
  endif
ENDM
xlsDisconnect MACRO topic
  ifb <topic>
	push xsDiscAll
	push eax	; whatever, discard
  else 
	push xsDisc
	push repargA(topic)
  endif
  call MbXls$
ENDM
xlsCommand MACRO strarg
LOCAL tmp$
  if (opattr strarg) ne atRegister
	ife @InStr(1, <strarg>, <[>) * @InStr(1, <strarg>, <]>)
		tmp$ CATSTR <## xlsCommand error, line >, %@Line, <: >, <strarg>, < has no [brackets] ##>
		.err tmp$
	endif
  endif
  push xsCmd
  push repargA(strarg)
  call MbXls$
ENDM
xlsOpen MACRO strarg
  push xsOpen
  push repargA(strarg)
  call MbXls$
ENDM
xlsClose MACRO sav:=<2>
  push xsClose
  push sav
  call MbXls$
ENDM
xlsFormat MACRO arg	; xf CF_whatever before read or write
  push xsCF
  push arg
  call MbXls$
ENDM

xlsWrite MACRO RowCol0, strarg0
LOCAL twoX, RowCol, strarg
  twoX=0
  ifb <strarg0>
	RowCol equ <0>
	strarg equ <RowCol0>
  else
	RowCol equ <RowCol0>
	strarg equ <strarg0>
  endif
  ifidni RowCol, < EaX>
	ifidni strarg, <(eAx)>
		RowCol equ <dword ptr txXlsRc>	; xlsrc$(...), cat$(..)
	endif
  elseifidn strarg, <( eAx)>
	twoX=1
  endif
  push xsWrite
  ifidn RowCol, <0>
	push 0
  else
	push repargA(RowCol)
  endif
  ifidn RowCol, <( eAx)>
	ifidn <strarg>, <( eAx)>
		twoX=1
	endif
  endif
  if twoX
	push -1
	call MbGetSlotPointer	; -1=get previous
	mov eax, [edx]
  elseifdif strarg, <( eAx)>
	ifdifi strarg, <eax>
		mov eax, repargA(strarg)
	endif
  endif
  call MbXls$
ENDM
xlsSysRead$ MACRO topic
  push xsSysRead
  push repargA(topic)
  call MbXls$
  EXITM <eax>
ENDM
xlsRead$ MACRO RowCol
  push xsRead
  ifidn <RowCol>, <0>
	push 0
  elseifb <RowCol>
	push 0
  else
	push repargA(<RowCol>)
  endif
  call MbXls$
  EXITM <eax>
ENDM
xlsR equ <"R">
xlsC equ <"C">
xlsRC$ MACRO r1:=<1>, c1:=<1>, r2, c2
  ifndef txXlsRc
	.DATA?
	txXlsRc db 32 dup(?)
  	.CODE
  endif
  push edi
  mov edi, offset txXlsRc+4
  push edi
  push -2
  push Str$(r1)
  mov al, xlsR
  stosb
  push edi
  call MbCopy
  xchg eax, edi
  mov al, xlsC
  stosb
  invoke MbCopy, edi, Str$(c1), -1
  ifnb <r2>
	xchg eax, edi
	dec edi
	mov al, ":"
	stosb
	mov al, xlsR
	stosb
	invoke MbCopy, edi, Str$(r2), -2
	xchg eax, edi
	mov al, xlsC
	stosb
	invoke MbCopy, edi, Str$(c2), -1
  endif
  pop eax
  mov [eax-4], eax	; copy of slot pointer
  pop edi
  EXITM < EaX>	; e.g. R1C2 or R1C2:R3C4
ENDM
xlsHotlink MACRO range:=<0>, pCB 	; no args=System
LOCAL isH
  ifnb <pCB>
	isCb INSTR <pCB>, <cb:>
	if isCb
		mov eax, @SubStr(<pCB>, isCb+3)	; pass address of callback proc
		push xsHotlinkCb
	else
		mov eax, pCB	; pass handle of control
		push xsHotlinkCbHc
	endif
  else
	push xsHotlink	; leave cb "as is"
  endif
  ifidn <range>, <0>
	push 0
  else
	push repargA(range)
  endif
  call MbXls$
ENDM
xlsErr$ MACRO arg
  push xsErr$
  push eax
  call MbXls$
  EXITM <eax>
ENDM
xlsPixels2Points MACRO px, py
    push esi
    push edi
    push ecx
    TWIPSPERINCH=1440
    if (opattr px) eq atImmediate
	mov esi, px*TWIPSPERINCH/20
    else
	imul esi, px, TWIPSPERINCH/20
    endif
    if (opattr py) eq atImmediate
	mov edi, py*TWIPSPERINCH/20
    else
	imul edi, py, TWIPSPERINCH/20
    endif
    invoke GetDC, 0
    push eax		; for ReleaseDC
    push 0
    push LOGPIXELSX
    push eax
    push LOGPIXELSY
    push eax
    call GetDeviceCaps	; .., hDC, LOGPIXELSY
    xchg eax, edi
    idiv edi
    xchg eax, edi	; y
    call GetDeviceCaps	; .., hDC, LOGPIXELSX
    xchg eax, esi
    idiv esi
    xchg eax, esi	; x
    call ReleaseDC	; invoke ReleaseDC, 0, hDC
    xchg eax, esi
    mov edx, edi	; y
    pop ecx
    pop edi
    pop esi
ENDM
ddeConnect MACRO servertopic
LOCAL svt, tmp$
  svt INSTR <servertopic>, <|>
  ife svt
	.err @CatStr(<## line >, %@Line, <: ddeConnect syntax is "server|topic" ##>)
  else
 	tmp$ CATSTR <Chr$(>, @SubStr(<servertopic>, 1, svt-1), <")>
	mov xlsServer$, tmp$	; e.g. Firefox
 	tmp$ CATSTR <Chr$(">, @SubStr(<servertopic>, svt+1), <)>
	mov xlsServer$[4], tmp$	; e.g. WWW_OpenURL
	xlsConnect
  endif
ENDM
ddeCommand MACRO strarg
  push xsCmd
  push repargA(strarg)
  call MbXls$
ENDM
ddeRequest$ MACRO topic
  push xsSysRead
  push repargA(topic)
  call MbXls$
  EXITM <eax>
ENDM
ddeDisconnect equ xlsDisconnect

; ###### Toolbar handling ######
TBarSUB STRUCT
  hTBar	dd ?
  hTTip	dd ?
  language	dd ?	; 8
  TitleUtf8$	dd ?	; 12
  DocUtf8$	dd ?	; 16
  hMenu	dd ?	; 20
  tbButtonSize	dd ?	; 24
  tbPt	POINT <>
  tbWP	dd ?	; old WinProc
  tbIndex	dd ?
  tbButtons	dd ?
  tbBase	dd ?
  TTip	MbTOOLINFO <>
	dd ?		; for playing with extra member of structure
  hTbControls	dd 8 dup(?)	; 28+x for TBarControl
  tbMap	db 56 dup(?)	; 012ABC??
  tbTemp	dd ?, ?
TBarSUB ENDS
gtbOdd=0
GuiToolbar MACRO tbid
  ifb <id>
	.err <## GuiToolbar(id) ##>
  else
	gtbOdd=gtbOdd+4
	if gtbOdd ge 4
		gtbOdd=0
	endif
	push ecx
	invoke GetDlgItem, tbs0.hTBar, tbid
	mov tbs0.tbTemp[gtbOdd], eax
	pop ecx
  endif
  EXITM <tbs0.tbTemp[gtbOdd]>
ENDM
TBarControl MACRO inx
  EXITM <tbs0.hTbControls[4*inx]>
ENDM
mbguiHwnd macro
  ifndef hWnd0
	exitm <hGui>
  else
	exitm <hWnd>
  endif
endm
GuiLanguage MACRO cc
  PushXPM cc
  ExternDef tbs0:TBarSUB
  pop dword ptr tbs0[8]
ENDM
SetMenuLanguage MACRO sml
  GuiLanguage sml
  push mbguiHwnd()
  GuiSMP PROTO :DWORD
  call GuiSMP
ENDM
wGetDoc$ MACRO arg
  EXITM wRec$(GetDoc$(arg))
endm
GetDoc$ MACRO arg:=<0>
  if @InStr(1, <arg>, <full>)
	exitm <tbs0.DocUtf8$>
  else
	push ecx
	mov ecx, tbs0.DocUtf8$
	.if Rinstr(ecx, "\")
		inc eax
		xchg eax, ecx
	.endif
	xchg eax, ecx
	pop ecx
	exitm <eax>
  endif
ENDM
SetDoc$ MACRO fname, nt$:VARARG
  Let tbs0.DocUtf8$=fname
  ifb <nt$>
	SetTitle$
  elseife @InStr(1, <nt$>, <no>)
	if @InStr(1, <nt$>, <full>)
		SetTitle$ 1
	else
		SetTitle$
	endif
  endif
ENDM
SetTitle$ MACRO fname
  push ecx
  ifb <fname>
	mov ecx, tbs0.DocUtf8$
	void Rinstr(ecx, "\")
	inc eax
	xchg eax, ecx
  elseifidn <fname>, <1>
	mov ecx, tbs0.DocUtf8$
  else
	mov ecx, repargA(fname)
  endif
  Let tbs0.TitleUtf8$=Replace$(Lg$($Title), "N$", ecx)
  wSetWin$ mbguiHwnd()=wRec$(eax)
  pop ecx
ENDM

wSetDoc$ MACRO fname, nt$:VARARG
  wLet tbs0.DocUtf8$=fname
  ifb <nt$>
	wSetTitle$
  elseife @InStr(1, <nt$>, <no>)
	if @InStr(1, <nt$>, <full>)
		wSetTitle$ 1
	else
		wSetTitle$
	endif
  endif
ENDM
wSetTitle$ MACRO fname
  push ecx
  ifb <fname>
	add wRinstr(tbs0.DocUtf8$, "\"), eax
	add eax, tbs0.DocUtf8$
	xchg eax, ecx
  elseifidn <fname>, <1>
	mov ecx, tbs0.DocUtf8$
  else
	mov ecx, repargW(fname)
  endif
  ; Let dword ptr tbs0[12]=wReplace$(Lg$($Title), "N$", ecx)	not implemented
  wSetWin$ mbguiHwnd()=ecx
  pop ecx
ENDM

MbFlagWin = 0	; 4096, bh==16 if active: Win$ assign
MbWideLet = 0
wSetWin$ MACRO arg1:REQ
LOCAL is, handle, getit
  is INSTR <arg1>, <=>
  handle SUBSTR <arg1>, 1, is-1
  push handle
  pop hSetWin
  swargs SUBSTR <arg1>, is
  getit CATSTR <Let eax>, swargs
  MbWideLet = 1024			
  MbFlagWin = 4096		; bh==16, Win$ assign
  getit
ENDM

wRec$ MACRO arg	; wSetWin$ hEdit=wRec$(Trim$(L$(1)))
  push arg  		; i.e. converts recalled UTF8$ to true Unicode
  call MbwRec		; under MbPrint; see also RecallP
  EXITM emArr$
ENDM

Utf8$ MACRO wString	; SetWin$ hEdit=Utf8$(wChr$("Hallo"))
  push wString
  MbUtf8 PROTO
  call MbUtf8		; under MbPrint; see also RecallP
  EXITM emArr$
ENDM
MsgTable$ MACRO msgID, msgDll
LOCAL is
  is INSTR <msgID>, <#>
  ife is
	push -1
	push msgID
  else
	Print msgID, Utf8Bom
	push @SubStr(<msgID>, 2, 1)
	push 0
  endif
  ifb <msgDll>
	push 1
  elseifidni <msgDll>, <"ntdll.dll">
	push 1
  elseifidni <msgDll>, <"kernel32.dll">
	push 2
  elseifidni <msgDll>, <2>
	push 2
  elseifidni <msgDll>, <0>
	push 0
  else
	push repargA(msgDll)
  endif
  MsgTableP PROTO :DWORD, :DWORD, :DWORD
  call MsgTableP
  EXITM <eax>
ENDM
SetSel$ MACRO hrTxU8:VARARG
LOCAL is, is2, tmp$
  tmp$ CATSTR <hrTxU8>, <,>
  is INSTR <hrTxU8>, <=>
  ifndef MbStex
	.DATA
	MbStex SETTEXTEX <ST_SELECTION or ST_KEEPUNDO, CP_UTF8>
	.CODE
  endif
  if is
	invoke SendMessage, @SubStr(<hrTxU8>, 1, is-1), EM_SETTEXTEX, addr MbStex, repargA(@SubStr(<hrTxU8>, is+1))
  else
	is INSTR <hrTxU8>, <flag>
	if is
		is2 INSTR is+4, tmp$, <,>
		m2m MbStex.flags, @SubStr(<hrTxU8>, is+6, is2-is-6)
	endif
	is INSTR <hrTxU8>, <cp>
	if is
		is2 INSTR is+2, tmp$, <,>
		mov MbStex.codepage, @SubStr(<hrTxU8>, is+3, is2-is-3)
	endif
  endif
ENDM
SetWin$ MACRO arg1:REQ, argsci
LOCAL is, handle, getit
  is INSTR <arg1>, <=>
  handle SUBSTR <arg1>, 1, is-1
  push handle
  pop hSetWin
  swargs SUBSTR <arg1>, is
  getit CATSTR <Let eax>, swargs
  MbFlagWin = 4096	; bh==16, Win$ assign
  ifnb <argsci>
	ifdif <argsci>, <sci>
		.err @CatStr(<## invalid 2nd arg ">, <argsci>, <" in line >, %@Line, < ##>)
	endif
	MbFlagWin=4096+8192
  endif
  getit
ENDM
; *** Let & Print macros *** (for use with MbPrint)
wLet MACRO args
  MbWideLet = 1024
  Let args
ENDM

uLet MACRO args
  MbWideLet = 1024
  u82w=1
  Let args
ENDM

MbFlagLMR = 2048	; LMR assign ->bh==8
MbPrintLet equ <MbPrint>	; for testing, just copy this line and change it to e.g. MbPrint2
; MbGetKeyP PROTO	; you will need 
; MbStdOut PROTO	; these two also
Let MACRO arg
LOCAL is, stL, stR, umz, dest, src, tmp$, spos, argct, s34, is1, is2, nu$, srcL$, srcR$, srcM$, srcO$, xItem, blPos, brPos
  if MbUseErrLine
	mov MbErrLine, @Line	; ten bytes longer
  endif
  psct = 0		; two global
  is INSTR <arg>, <=>
  dest SUBSTR <arg>, 1, is-1
  if xsLoopLet eq @Line
	ifidn dest, emArr$
		.if !eax
			mov edx, MbArrTable[4*stLastID]
			mov eax, [edx]
			.if dword ptr [edx+8*eax+StringArrHeader]==0
				dec dword ptr [edx]	;;jcL
			.endif
			xor eax, eax
			.Break
		.endif
	else
		.Break .if !eax
	endif
	ifdef ctExtract$
		inc ctExtract$
	endif
  endif
  xsLoopLet=0
  tmp$ SUBSTR <arg>, is+1
  src CATSTR tmp$, <+z>	;; src CATSTR @SubStr(<arg>, is+1), <+z> fails with JWasm
  c34$ equ <">
  s34 INSTR src, <'>
  if s34 eq 1
	c34$ equ <'>	; first quote is char 39
  else
	s34 INSTR src, <">
  endif
  ife s34			; no strings found, might be a struct
	stL INSTR dest, <[E>
	is2 INSTR dest, <[EL:>
	stR INSTR is, <arg>, <]>
	if is2
		push stLastID
		push @SubStr(<arg>, 5, is-6)	; dest
		push @SubStr(<arg>, is+5, stR-is-5)	; src
		call MbStructCopy
		EXITM
	elseif stL
		tmp$ CATSTR <## Let var=num not implemented in Line >, %@Line
		.err tmp$
	endif
  else
  	ifndef MbLsCt
		MbLsCt=0	;; global counter for string offsets
	endif
  	.DATA
	WHILE s34
		is2=s34
		MbLsCt=MbLsCt+1
		s34 INSTR is2+1, src, c34$
		srcL$ SUBSTR src, 1, is2-1
		srcR$ SUBSTR src, s34+1
		if s34 gt is2+1
			nu$ SUBSTR src, is2, s34-is2+1			;; nu$ equ @SubStr(src, o34, s34-o34+1) does not work
			srcO$ CATSTR <MbLs>, %MbLsCt
			if u82w
				@CatStr(srcO$, < db >, nu$, <, 0>)
				srcM$ CATSTR <OffSet >, srcO$
			else
				if MbWideLet
				  @CatStr(srcO$, < db 14, >, nu$, <, 0>)		;; add MbUnicodeMarker
				else
				  @CatStr(srcO$, < db >, nu$, <, 0>)
				endif
				srcM$ CATSTR <offset >, srcO$
			endif
		else
			srcM$ equ offset MbArrEmpty			;; Null$
		endif
		src CATSTR srcL$, srcM$, srcR$
		s34 INSTR src, c34$
	ENDM
	.CODE
  endif
  umz INSTR dest, <Use_mov_z$>
  ife umz					; if not Left$/Mid$/Right$ assignment
	ife MbFlagWin	; if not SetWin$
		ifdif emArr$, dest	; push dest, bit 30 set
			% is2 INSTR <dest>, <.>
			if is2 and type(dest) eq BYTE
				push 1
				call MbGetSlotPointer
				lea eax, dest
				mov [edx], eax		; pass address and len
				is1 INSTR dest, <+>
				is2 INSTR dest, <].>
					if is1 and (is2 gt is1)
						srcL$ SUBSTR dest, 6, is1-6
						srcR$ SUBSTR dest, is2+1
						srcL$ CATSTR srcL$, srcR$
						push sizeof srcL$
						pop dword ptr [edx+4]				; SetGlobals len
					else
						mov dword ptr [edx+4], sizeof dest
					endif
				umz=1
			else
				push dest	; non-array, and not Left$ etc: first extra argument serves to heapfree the destination
			endif
		endif
	endif
  endif
  argct = MbWideLet
  spos = 1
  WHILE is
  	blPos INSTR spos, src, <[>
  	brPos INSTR spos, src, <]>
	is INSTR spos, src, <+>
	if is
		if (is gt blPos) and (is lt brPos)
			xItem SUBSTR src, blPos, brPos-blPos+1
			argct = argct + 1
			push DWORD PTR xItem
			spos=brPos+2	; filter out SetGlobals etc
		else
			xItem SUBSTR src, spos, is-spos
			is2 INSTR xItem, <OffSet>
			if is2
				push xItem
				if MbWideLet
				  tmp$ CATSTR <** use "text", not wChr.$("text") in line >, %@Line, < **>
				  % echo tmp$
				else
				  call MbwRec
				  push eax
				endif
			else
				ifidni xItem, <eax>
						ifidn emArr$, dest
							xItem equ <MbFlags[40]>	; ??? really used ???
						endif
				endif
				PushString xItem, 1	;; push all the others
			endif
			argct = argct + 1
			spos = is+1
		endif
	endif
  ENDM
  MbWideLet = 0
  is=argct and 63
  if is gt 31
	.err @CatStr(<## line >, %@Line, <: max 31 args with Let, now >, %is, < ##>)
  endif
  ifidn emArr$, dest		;; Array
	push argct or 080000000h	;; push count, set bit 31 only
  elseif umz			;; Let Mid$(My$(3) does not count as array
	if jjtest
		INT 3
	endif
	push argct or MbFlagLMR		;; push count plus a flag for Left$ Mid$ Right$
  elseif MbFlagWin
	push argct or MbFlagWin		;; push count plus a flag for SetWin$
	MbFlagWin = 0
  else
	push argct or 0c0000000h		;; normal string: push the count, set bit 30 and 31
  endif
  u82w=0
  ifdef jAct$
	jAct$
  endif
  call MbPrintLet		; Let end
  ife umz
	ifdif emArr$, dest		; flags: bits 30+31, MbFlagLMR, MbWideLet, MbInkey, MbWidePrint	
		ifdifi <eax>, dest
				mov dest, eax
			endif
	endif
   endif
ENDM

At MACRO px:REQ, py			; Syntax is Print At(1,1) CColor(cRed, cBlue) "Whatever" - no comma!!
  ifb <py>
	Locate(px, Locate(y))
  else
	Locate(px, py)
  endif
  EXITM <>
ENDM
CCol$ equ <>
CColor MACRO cols:VARARG
  LOCAL tmp$
  tmp$ CATSTR <cols>
  ifdif tmp$, CCol$
	ConsoleColor cols
	CCol$ equ tmp$
  endif
  EXITM <>
ENDM
Locate MACRO lx, ly
LOCAL csbiSize, is, subX, loL$, loR$, loPM$
  ifb <ly>
	push ecx
	invoke GetStdHandle, STD_OUTPUT_HANDLE
	csbiSize=(CONSOLE_SCREEN_BUFFER_INFO+4) AND 11111100b	; align 4, 24
	sub esp, csbiSize	; create a slot
	push esp
	push eax
	call GetConsoleScreenBufferInfo
	ifidni <lx>, <x>
		movzx eax, word ptr [esp.CONSOLE_SCREEN_BUFFER_INFO.dwCursorPosition]
	else
		movzx eax, word ptr [esp.CONSOLE_SCREEN_BUFFER_INFO.dwCursorPosition+2]
	endif
	add esp, csbiSize
	pop ecx
	EXITM <eax>	; e.g. mov ebx, Locate(y)
  else
	PushPlusMinus ly
	is INSTR <lx>, <*>
	if is
		loL$ SUBSTR <lx>, 1, is-1
		loR$ SUBSTR <lx>, is+1
		is INSTR loR$, <+>
			subX INSTR loR$, <->
			if is
				loPM$ SUBSTR loR$, is+1
				loR$ SUBSTR loR$, 1, is-1
			elseif subX
				loPM$ SUBSTR loR$, subX+1
				loR$ SUBSTR loR$, 1, subX-1
			endif		; At(ecx*8+3, ...
			imul eax, loL$, loR$
			if subX
				sub eax, loPM$
			elseif is
				add eax, loPM$
			endif
			push eax
	else
		PushPlusMinus lx
	endif
	LocateP PROTO
	call LocateP
	EXITM <>	; e.g. Locate(3, 5)
  endif
ENDM

MbInkey =		0	; These five must be in front of wPrint/Print
MbWidePrint =		0
MbWidePrintConsole =	0
MbUTF8 =		0
Mb1252 =		0
wInkey MACRO args:VARARG
  ifnb <args>
	MbInkey=32 or 1024
	wPrint args
  else
	MbGetKeyP PROTO
	call MbGetKeyP
  endif
ENDM

uInkey MACRO args:VARARG
  ifnb <args>
	MbInkey=32 or 1024
	uPrint args
  else
	MbGetKeyP PROTO
	call MbGetKeyP
  endif
ENDM
MbCpAnsi=1252
SetCpAnsi macro forceCp:=<0>	; no arg=force, 1=auto
  MbUTF8=forceCp-1
  if forceCp eq 0 or Mb1252 eq 0
	pushad
	MbXms
	mov eax, MbCpAnsi		; 1252, standard Windows codepage
	push eax
	invoke SetConsoleCP, eax
	call SetConsoleOutputCP
	MbXmr
	popad
	Mb1252=1
  endif
ENDM
MbCpUtf8=CP_UTF8
SetCpUtf8 macro forceCp:=<0>	; no arg=force, 1=auto
  Mb1252=forceCp-1
  if forceCp eq 0 or MbUTF8 eq 0
	pushad
	MbXms
	mov eax, MbCpUtf8		; 65001 aka CP_UTF8 - Unicode as multibyte
	push eax
	invoke SetConsoleCP, eax
	call SetConsoleOutputCP
	MbXmr
	ConsoleColor wPrintColor		; needed for Unicode on some systems
	popad
	MbUTF8=1
  endif
ENDM
SetCpUpperLower$ MACRO src:=<0>, dest
  mov MbFlags[-32], src
  ifnb <dest>
	mov MbFlags[-28], dest
  else
	mov MbFlags[-28], src
  endif
ENDM
ConvertCp$ MACRO src, srcCp, destCp
Local srcReg, lblErr
  push esi
  push edi
  push ecx
  ifidni <src>, <esi>
	srcReg equ <edi>
  else
	srcReg equ <esi>
	mov esi, repargA(src)
  endif
  call MbBufferGet
  xchg eax, edi
  MbXms
  invoke MultiByteToWideChar, srcCp, 0, esi, -1, edi, 0	; req size in wide characters
  .if eax>MbBufSize/16
	lblErr:		; eax is chars, not bytes, and we need two buffers
	mov eax, Mirror$("ovfl")
	stosd
  .else
	inc eax
	lea edx, [edi+MbBufSize/16+1]
	push edx
	invoke MultiByteToWideChar, srcCp, 0, esi, -1, edx, eax
	pop esi
	invoke WideCharToMultiByte, destCp, 0, esi, eax, edi, MbBufSize/16, 0, 0
	dec eax
	js lblErr
	add edi, eax
  .endif
  MbXmr
  push 1
  push edi
  call MbBufferFix
  pop ecx
  pop edi
  pop esi
  Exitm emArr$
ENDM
wPrintColor = cGray		; user may change this
wPrint MACRO args:VARARG
  ifnb <args>
	ifidn @SubStr(<args>, 1, 1), <#>
		MbWidePrint = 1024+2048		; bh==4+8
	else
		MbWidePrintConsole = 1024
	endif
  endif
  Print args
ENDM

uPrint MACRO args:VARARG
  u82w=1
  wPrint args
ENDM

Inkey MACRO args:VARARG
  ifnb <args>
	MbInkey=32
	Print args
  else
	MbGetKeyP PROTO
	call MbGetKeyP
  endif
ENDM

MbPSets STRUCT
mLeft	dw ?
mTop	dw ?
mRight	db ?
mBottom	db ?
ask4Dlg	db ?
res1	db ?
MbPSets ENDS
PrintRtf MACRO hPre, dlgPrt:=<1>, mgL, mgT, mgR, mgB
Local is, tmp$
  ExternDef MbPS:MbPSets
  ifdif <dlgPrt>, <1>
	mov MbPS.ask4Dlg, dlgPrt
  endif
  push hPre
  ifnb <mgL>
	is INSTR <mgL>, <margins:>
	if is
		tmp$ SUBSTR <mgL>, 9
		push esi
		ifdifi tmp$, <esi>
			mov esi, tmp$
		endif
		lodsd
		mov MbPS.mLeft, ax
		lodsd
		mov MbPS.mTop, ax
		lodsd
		mov MbPS.mRight, al
		lodsd
		mov MbPS.mBottom, al
		pop esi
	else
		mov MbPS.mLeft, mgL
	endif
  endif
  ifnb <mgT>
	mov MbPS.mTop, mgT
  endif
  ifnb <mgR>
	mov MbPS.mRight, mgR
  endif
  ifnb <mgB>
	mov MbPS.mBottom, mgB
  endif
  MbPrintRtf PROTO :DWORD
  call MbPrintRtf
  EXITM <eax>
ENDM
SubSysWarn=0	; 1=no warning
InkeySubWin=0	; 1=use Inkey without console
Print MACRO FirstString, strings:VARARG
LOCAL hashX, is, argct, tmp$, c1$
  psct = 0	; global
  argct = 1
  ifb <FirstString>
	PushString CrLf$	;; a Print without any args means CRLF
  else
	c1$ SUBSTR <FirstString>, 1, 1
	ifidn c1$, <#>
		argct = 0	; arg1 was the file number
		hashX SUBSTR <FirstString>, 2	; #1, #1:123, #ebx, #ebx:123, #xy, #xy:ebx, ....
		is INSTR <FirstString>, <:>
		if is
			hashX SUBSTR <FirstString>, 2, is-2
			push @SubStr(<FirstString>, is+1)	; #n:bytes
			pop MbBytes2Write
		elseifb <strings>
			PushString CrLf$
			argct = 1
		endif
	else
		% is INSTR <FirstString>, <+>	;; ML needs %
		if is
			ifdif c1$, <">
				tmp$ CATSTR <## Use commas, not '+' to separate str>, <ings in Print (line >, %@Line, <) ##>
				% echo tmp$
			endif
		endif
		% PushString <FirstString>, 1	;; first arg on the stack
	endif
  endif
  FOR item, <strings>
	argct = argct + 1
	PushString item, 1	;; push all other strings
  ENDM
  is=argct and 63
  if is gt 31
	.err @CatStr(<## line >, %@Line, <: max 31 args with Print, now >, %is, < ##>)
  endif
  ifdef hashX
	if (opattr hashX) eq atImmediate
		push (hashX+1)*64+(argct or MbInkey or MbWidePrintConsole or MbWidePrint) 	;; push the count and the flag
	else
		imul eax, hashX, 64
		add eax, 64+(argct or MbInkey or MbWidePrintConsole or MbWidePrint)
		push eax
	endif
  else
	if MbInkey or SubSysWarn eq 0
		SubSysWarn=1
		if @Line le 1000
			ifidni SubSys, <Windows>
				tmp$ CATSTR <*** Warning, line >, %@Line, <: Print and Inkey need subsystem console, Inkey disabled because it would block your program ***>
				% echo tmp$
				MbInkey=32*InkeySubWin
			endif
		endif
	endif
	push argct or MbInkey or MbWidePrintConsole or MbWidePrint			;; push the count and the flag
  endif
  u82w=0
  call MbPrintLet
  MbInkey = 0		;; force normal mode again
  MbWidePrint = 0
  MbWidePrintConsole = 0
ENDM

PrintLine MACRO args:VARARG
  ifb <args>
	Print
  else
	Print args, CrLf$
  endif
ENDM
wPrintLine MACRO args:VARARG
  ifb <args>
	wPrint
  else
	wPrint args, wCrLf$
  endif
ENDM

uPrintLine MACRO args:VARARG
  ifb <args>
	wPrint
  else
	u82w=1
	wPrint args, wCrLf$
  endif
ENDM

PrintBuffer MACRO wbFile:REQ, wbBuffer:REQ, wbBytes
LOCAL fnu2, wb2, is, tmp, pBuf
  fnu2  SUBSTR <wbFile>,1,1
  ifidn fnu2,<#>
	fnu2 SUBSTR <wbFile>, 2
  endif
  is INSTR fnu2, <:>
  if is
	ifnb <wbBytes>
		tmp CATSTR <## 3rd arg not allowed in line >, %@Line, < ##>
		% echo tmp
		.err
		EXITM
	endif
	wb2 SUBSTR fnu2, is+1
	fnu2 SUBSTR fnu2, 1, is-1
  else
	wb2 equ <wbBytes>
  endif
  ifidni <wbBuffer>, <ESP>
	mov eax, esp	; before push ecx, edx!
	pBuf equ <eax>
	if usedeb
		% echo @CatStr(<** >, %@Line, <: using current esp as buffer start **>)
	endif
  else
	pBuf equ <wbBuffer>
  endif
  push ecx		; MBABI
  push edx
  % is INSTR <wbBuffer>, <[Edx.>
  ifidni <wbBuffer>, <edx>
	is=1
  endif
  tmp equ <edx>
  if is
	ifidni wb2, <eax>
		tmp equ <ecx>
	else
		tmp equ <eax>
	endif
  elseifidni wb2, <edx>
	ifidni <wbBuffer>, <eax>
		tmp equ <ecx>
	else
		tmp equ <eax>
	endif
  endif
  mov tmp, esp
  invoke WriteFile, [MbFH+4*fnu2], pBuf, wb2, tmp, 0
  pop eax
  pop ecx
ENDM

CatLen equ Len(MbCat$)
Cat$ MACRO args:VARARG
LOCAL tmp$
  ife @InStr(, <args>, <+>)
	if @InStr(, <args>, <,>)
		tmp$ CATSTR <## Error line >, %@Line, <: use plus sign in Cat$ ##>
		% echo tmp$
		.err
		exitm <eax>
	endif
  endif
  Let MbCat$=args
  EXITM <(eAx)>
ENDM

wCatLen equ wLen(MbCat$)
wCat$ MACRO args:VARARG
  wLet MbCat$=args
  EXITM <(eAx)>
ENDM

uCat$ MACRO args
  u82w=1
  wLet MbCat$=args
  EXITM <(eAx)>
ENDM

PushPs macro num, arg
LOCAL tmp$
  push num
  if MbWidePrintConsole or MbWidePrint
	% echo @CatStr(<## Warning: use w??$ in line >, %@Line, < ##>)
  endif
ENDM

psct=0	;; avoids error if ps comes before calling macros
push127 MACRO
  push 127
ENDM

PushString macro arg:REQ, LPonly
LOCAL quot, hasq, nustr, needslea, sc, src, tmp$, is, is2, srcL$, srcR$, psWide
  psWide=MbWidePrint or MbWideLet or u82w or (ucInstr and 128) or MbWidePrintConsole
  src equ <arg>
  While 1
	tmp$ SUBSTR src, 1, 1
	ifdif tmp$, < >
		EXITM
	endif
	src SUBSTR src, 2
  ENDM
  psct = psct + 1
  hasq INSTR src, <Use_mov>
  sc INSTR src, <Use_Let>
  % is INSTR <arg>, <OFFSET>
  if is eq 1
	push arg
  elseif hasq eq 1
	push127								;; flag it's a normal text slot
  elseif sc eq 1
	ifb <LPonly>	; since 3/2010
		tmp$ CATSTR <## PushString line >, %@Line, <: bad usage ##>
		% echo tmp$
		.err
	endif
	push127								;; flag Replace$
  elseifidn <( eAx)>, src
	push127								;; flag it's a normal text slot
  elseifidn <( EdX)>, src					;; Res$ etc
	push127		;; flag it's a normal text slot -> esi==126
  elseifidn emArr$, src						;; only arrays produce this code as output of My$()
	push127		;; flag it's a normal text slot -> esi==126
  elseifidn <MbC:>, src
	push -111		;; flag clipboard -> esi==-111

; predefined slots:
; 0	Nullpointer
; 1	CrLf$			; offset to 13, 10, 0
; 2	Tb$				; offset to 9, 0
; 3	Spc1$			; offset to 32, 0
; 4	Spc2$			; offset to 32, 32, 0
; 5	Spc4$
; 6	MbExeFolder$	; offset to \Masm32\..\MyProg.exe

  elseifidn src, <CrLf$>
	if psWide
	  	push wCrLf$
	else
		PushPs 1, src
	endif
  elseifidn src, <Tb$>
	if psWide
	  	push wTb$
	else
	  	PushPs 2, src
	endif
  elseifidn src, <Spc1$>
  	PushPs 3, src
  elseifidn src, <Spc2$>
  	PushPs 4, src
  elseifidn src, <Spc4$>
  	PushPs 5, src
  elseifidn src, <MbExeFolder$>
  	PushPs 6, src
  else
  	needslea equ <no>		;; default: no lea needed
	sc SIZESTR src
	if sc gt 5
		needslea SUBSTR src, 1, 4	;; may contain "addr"
	endif
	quot SUBSTR src, 1, 1
	hasq INSTR src, <">
	ife hasq
		hasq INSTR src, <'>
		ife hasq
			ifidn needslea, <no>
				if (OPATTR arg) eq 36	;; for the Print "test", 13, 10, "me" syntax
					hasq = 1
				endif
			endif
		endif
	endif
	if hasq
		if psWide						; PushString: or MbWideLet: handled differently
			if u82w or ucInstr
				push repargA(src)
				call MbwRec
				push eax
			else
				push wChr$(src)
			endif
		else
			push repargA(src)
		endif
	else
		ifidni <addr>, needslea
			src SUBSTR src, 5		;; get rid of "addr "
			sc = OPATTR(src)
			is INSTR src, <[ebx+>	; setglobals
			if (sc eq 98) or is
				push eax			;; create a stack slot
				push eax			;; save eax
				lea eax, src
				mov [esp+4], eax	;; and 'push' the address
				pop eax
			else
				tmp$ CATSTR <push offset >, <src>
				tmp$
			endif
		else
		% is INSTR <src>, <.>
		if is and type(src) eq BYTE
			push 1
			call MbGetSlotPointer
			lea eax, src
			mov [edx], eax	; pass the address
			push ecx
			or ecx, -1
			mov [edx], eax		; pass the address
			is INSTR src, <+>
			is2 INSTR src, <].>
			if is and (is2 gt is)
				srcL$ SUBSTR src, 6, is-6
				srcR$ SUBSTR src, is2+1
				srcL$ CATSTR srcL$, srcR$
				is2=sizeof srcL$
			else
				is2=sizeof src
			endif
			.Repeat
				inc ecx
			.Until byte ptr [eax+ecx]==0 || ecx>=is2
			mov dword ptr [edx+4], ecx	; and the len
			pop ecx
			push 127	; a slot
		else
				push src			;; else pass src
		endif
		endif
	endif
  endif
ENDM

MbIsWide macro args
  if @InStr(1, <args>, <OffSet>) or @InStr(1, <args>, <( EdX)>) or @InStr(1, <args>, <( eAx)>) or @InStr(1, <args>, emArr$)
	EXITM <1>
  else
	EXITM <0>
  endif
ENDM

wInput$ MACRO prompt:=<0>, prefill:=<0>	; Inkey "[", Input$("Type some text and hit Enter: "), "]"
MbwInputStrP PROTO :DWORD, :DWORD
  if MbIsWide(prefill)	; is already a wChr$
	PushString prefill
  else
	push repargW(prefill)
  endif
  if MbIsWide(prompt)	; is already a wChr$
	PushString prompt
  else
	push cStyleW$(prompt)	; allows e.g. tab escape sequence
  endif
  SetCpUtf8 1		; needed
  call MbwInputStrP
  EXITM emArr$	; for Print, Let etc
ENDM
Input$ MACRO prompt:=<0>, prefill:=<0>, iFlush
  ifidn @SubStr(<prompt>, 1, 1), <#>	; Let esi=Input$(#1, 200)
	push prefill	; #bytes
	call MbBufferGet
	push eax		; buffer
	push @SubStr(<prompt>, 2)
	call MbInputP
	add edx, eax
	push 1
	push edx
	call MbBufferFix
  else	; Print Input$("Type some text and hit Enter: ", "pre")
	MbInputStrP PROTO :DWORD, :DWORD
	push repargA(prefill)
	push cStyle$(prompt)	; allows e.g. tab escape sequence
	SetCpAnsi 1	; needed
	ifidni <iFlush>, <flush>
		invoke FlushConsoleInputBuffer, rv(GetStdHandle, STD_INPUT_HANDLE)
	endif
	call MbInputStrP
  endif
  EXITM emArr$	; for Print, Let etc
ENDM
Input MACRO fnu:REQ, tostr:REQ, nBytes:REQ, noDel
LOCAL fnu2
  if MbUseErrLine
	mov MbErrLine, @Line
  endif
  fnu2 SUBSTR <fnu>, 2
  push nBytes
  push tostr
  push fnu2
  call MbInputP	  		;; invoke MbInputP, fnu2, tostr, nBytes
  ifb <noDel>
	mov byte ptr [edx+eax], 0	; set a zero delimiter
  endif
ENDM
Prompt$ MACRO title, proposal:=<0>, font:=<0>, proX, proY, proW, proH
ExternDef wcxP$:WNDCLASSEX
  push edi
  mov edi, offset wcxP$[-16]
  ifnb <proX>
	mov dword ptr [edi-16], proX
  endif
  ifnb <proY>
	mov dword ptr [edi-12], proY
  endif
  ifnb <proW>
	mov dword ptr [edi-8], proW
  endif
  ifnb <proH>
	mov dword ptr [edi-4], proH
  endif
  mov eax, repargA(title)
  stosd
  mov eax, repargA(proposal)
  stosd
  mov eax, font
  stosd
  pop edi
  PromptWM PROTO
  call PromptWM
  EXITM emArr$
ENDM
Open10=	0	; 1=allow #10 for internal functions 
MbWideOpen=	0
OpenForI$ equ	Open_for_input
OpenForO$ equ	Open_for_output
hMap equ	MbFH[4*11]	; CreateFileMapping
pMap equ	MbFH[4*12]	; MapViewOfFile
wOpen MACRO args:VARARG
  MbWideOpen = 64
  Open args
ENDM

Open MACRO mc:REQ, fnu:REQ, fname:REQ, search:=<0>
LOCAL fnu2, tmp$
  if MbUseErrLine
	mov MbErrLine, @Line	; ten bytes longer
  endif
  fnu2=@SubStr(<fnu>, 2)
  if fnu2 gt 9+Open10
	tmp$ CATSTR <## line >, %@Line, <: Open #0...9 ##'>
	.err tmp$
  endif
  Open10=0
  ifidni <mc>,<"m">
	if fnu2
		tmp$ CATSTR <## line >, %@Line, <: mode M only for #0 ##'>
		.err tmp$
	endif
  endif
  fnu2=fnu2+MbWideOpen
  ifidni <mc>,<"i">
	if MbWideOpen
		invoke OpenForI$, fnu2, repargW(fname), search
	else
		invoke OpenForI$, fnu2, repargA(fname), search
	endif
  else
	ifidni <search>, <nobom>	; suppresses BOM when wPrinting to a file
		push fnu2
	endif
	if MbWideOpen
		invoke OpenForO$, fnu2, repargW(fname), mc
	else
		invoke OpenForO$, fnu2, repargA(fname), mc
	endif
	ifidni <search>, <nobom>
		pop edx
		lea edx, [MbFH+4*edx]
		and byte ptr [edx-4*11], 126	; clear bit 0 of MbFHfg
	endif
  endif
  if usedeb
	.if eax==INVALID_HANDLE_VALUE
		pushad
		tmp$ CATSTR <PrintLine '## Line >, %@Line, <: Open &mc failed ##'>
		tmp$
		popad
	.endif
  endif
  MbWideOpen=0
ENDM

Rename Macro Src:REQ, Dest:REQ, dwFlags:=<0>	; flag e.g. MOVEFILE_REPLACE_EXISTING
  push ecx
  invoke MoveFileEx, repargA(Src), repargA(Dest), dwFlags
  pop ecx
ENDM

afnUC=0
wExist$ equ <dword ptr wfd[-4]>
Exist$ equ <dword ptr wfd[-4]>
Exist MACRO fname:REQ, DiscardHandle:=<1>
LOCAL tmp$
  ifidn <fname>, <( EdX)>
	tmp$ CATSTR <## Warning line >, %@Line, <: use wRes$ with Unicode resources ##>
	% echo tmp$
	push DiscardHandle or 2
  else
	push DiscardHandle or 0
  endif
  if afnUC
	afnUC=0
	LastFileDosName$ EQU offset wfd.cAlternateFileName
  else
	LastFileDosName$ EQU offset wfd[WIN32_FIND_DATA.cAlternateFileName]
  endif
  push repargA(fname)
  call MbExistP
  EXITM  <!Zero?>
ENDM
wExist MACRO fname:REQ, DiscardHandle:=<1>
  afnUC=1
  EXITM Exist(fname, DiscardHandle or 2)
ENDM
Fsnext macro dummy		;; for use in Mb2Masm
 invoke FindNextFile, FifHandle, addr wfd
 .if eax==0
	invoke FindClose, FifHandle
	xor eax, eax
	mov FifHandle, eax
  .endif
  EXITM <eax>
ENDM

IsFolder MACRO path
  push ecx
  invoke GetFileAttributes, repargA(path)
  inc eax
  and eax, FILE_ATTRIBUTE_DIRECTORY
  pop ecx
  EXITM <!Zero?>
ENDM
OfnFilters macro uc:REQ, arg:REQ
LOCAL is, is0, isR, xL$, xR$, tmp$, argByte, argWide, oa
  is INSTR <arg>, <=>
  ife is
	oa = (opattr arg) AND 127
	if oa eq atImmediate
		if uc
			EXITM repargW(arg)
		else
			EXITM repargA(arg)
		endif
	else
		push esi
		push edi
		push arg
		invoke MbBufferGet
		pop esi
		xchg eax, edi
		if uc
			.While 1
				lodsw
				.Break .if !ax
				.if al=="|" || al=="="
				  xor eax, eax
				.endif
				stosw
			.Endw
			stosb
		else
			.While 1
				lodsb
				.Break .if !al
				.if al=="|" || al=="="
				  xor eax, eax
				.endif
				stosb
			.Endw
			stosb
		endif
		push 1
		push edi
		call MbBufferFix
		pop edi
		pop esi
		EXITM <dword ptr [edx]>
	endif
  endif
  is0=1
  tmp$ equ <>
  WHILE is
	xL$ SUBSTR <arg>, is0, is-is0
	isR INSTR is, <arg>, <|>
	ife isR
		isR INSTR is, <arg>, <">
	endif
	xR$ SUBSTR <arg>, is+1, isR-is-1
	is INSTR isR, <arg>, <=>
	if uc
		if is
			tmp$ CATSTR tmp$, xL$, <", 13, ">, xR$, <", 13, ">
		else
			tmp$ CATSTR tmp$, xL$, <", 13, ">, xR$, <", 0, 0>
		endif
	else
		if is
			tmp$ CATSTR tmp$, xL$, <", 0, ">, xR$, <", 0, ">
		else
			tmp$ CATSTR tmp$, xL$, <", 0, ">, xR$, <", 0, 0>
		endif
	endif
	is0=isR+1
  ENDM
  if uc
	push esi
	xchg wRec$(repargA(tmp$)), esi
	push esi
	.Repeat
		lodsw
		.if ax==13
		  mov byte ptr [esi-2], 0
		.endif
	.Until !al
	pop esi
	xchg eax, esi
	pop esi
	EXITM <eax>
  else
	EXITM repargA(tmp$)
  endif
ENDM

ofnFlagsO=OFN_EXPLORER or OFN_ENABLESIZING or OFN_ENABLEHOOK or OFN_NODEREFERENCELINKS or OFN_CREATEPROMPT
ofnFlagsS=OFN_EXPLORER or OFN_ENABLESIZING or OFN_ENABLEHOOK or OFN_NODEREFERENCELINKS or OFN_OVERWRITEPROMPT or OFN_EXTENSIONDIFFERENT
ofnSortFlags=16*2+0		; 16*2=auto for date modified (there is no column 16...), +x 0=down (=latest first,), 1=up
wFileOpen$ MACRO filter, title:=<0>, curFile:=<0>, flags:=<ofnFlagsO>, sortflags:=<ofnSortFlags>
  ifb <filter>
	EXITM <MbOfn.lpstrFile>
  else
	push sortflags or 128
	push flags
	if (opattr curFile) ne atImmediate
		push curFile
	else
		push wRec$(repargA(curFile))
	endif
	push wRec$(repargA(title))
	push OfnFilters(1, filter)
	call MbOpenFile
	EXITM <!Zero?>
  endif
ENDM

wFileSave$ MACRO filter, title:=<0>, curFile:=<0>, flags:=<ofnFlagsS>, sortflags:=<ofnSortFlags>
  ifb <filter>
	EXITM <MbOfn.lpstrFile>
  else
	push sortflags or 64 or 128	; 128=w, 64=save
	push flags
	if (opattr curFile) ne atImmediate
		push curFile
	else
		push wRec$(repargA(curFile))
	endif
	push wRec$(repargA(title))
	push OfnFilters(1, filter)
	call MbOpenFile
	EXITM <!Zero?>
  endif
ENDM

FileOpen$ MACRO filter, title:=<0>, curFile:=<0>, flags:=<ofnFlagsO>, sortflags:=<ofnSortFlags>
  ifb <filter>
	EXITM <MbOfn.lpstrFile>
  else
	push sortflags
	push flags
	push repargA(curFile)
	push repargA(title)
	push OfnFilters(0, filter)
	call MbOpenFile
	EXITM <!Zero?>
  endif
ENDM

FileSave$ MACRO filter, title:=<0>, curFile:=<0>, flags:=<ofnFlagsS>, sortflags:=<ofnSortFlags>
  ifb <filter>
	EXITM <MbOfn.lpstrFile>
  else
	push sortflags or 64	; 64=save
	push flags
	push repargA(curFile)
	push repargA(title)
	push OfnFilters(0, filter)
	call MbOpenFile
	EXITM <!Zero?>
  endif
ENDM

FileOpenSetFolder MACRO arg
  push edi
  mov edi, offset MbOfn+OPENFILENAME
  invoke MbCopy, edi, repargA(arg), -1
  inc MbOfn.nMaxFile
  pop edi
ENDM

wFileOpenSetFolder MACRO arg
  push esi
  push edi
  mov edi, offset MbOfn+OPENFILENAME+MAX_PATH
  mov esi, repargW(arg)
  shl wLen(esi), 1
  invoke MbCopy, edi, esi, eax
  inc MbOfn.nMaxFile
  pop edi
  pop esi
ENDM

SetFolder MACRO arg
    invoke SetCurrentDirectory, repargA(arg)
ENDM

FolderOpen$ MACRO prompt:=<"Select a folder">, title:=<0>, initdir:=<0>, flags:=<BIF_NEWDIALOGSTYLE>
LOCAL is
  push flags
  ifidn <title>, <0>
	push 0
  else
	push repargA(title)
  endif
  push repargA(prompt)
  ifidn <initdir>, <0>
	push 0
  else
	is INSTR  <initdir>, <%>
	if is
		push ExpandEnv$(initdir)
	else
		push repargA(initdir)
	endif
  endif
  Browse4Folder PROTO :DWORD, :DWORD, :DWORD, :DWORD
  call Browse4Folder
  EXITM emArr$	; non-Zero? = success
ENDM

Close MACRO fnu:=<#11>	;; 0-8 allowed, 9+10 internal, blank means close all
  LOCAL fnu2, tmp$
  fnu2  SUBSTR <fnu>, 1, 1
  ifidn fnu2,<#>
	fnu2 SUBSTR <fnu>, 2
  endif
  push fnu2
  pop eax
  call MbClose
ENDM

Lof MACRO fnu:REQ
  if @InStr(1, <fnu>, <#>) eq 1
	push @SubStr(<fnu>, 2)
  elseif @InStr(1, <012345789>, <fnu>)
	push fnu
  else
	push repargA(fnu)
  endif
  call MbGetFileLen
  EXITM <eax>		; returns highword in edx; sign? set if error
ENDM

Loc MACRO hFile
LOCAL tmp$
  push ecx
  push eax
  push edx
  mov edx, esp
  if @InStr(1, <hFile>, <#>) eq 1
	; there is no GetFilePointer, but this works...
	invoke SetFilePointerEx, MbFH[4*@SubStr(<hFile>, 2,1)], 0, 0, edx, FILE_CURRENT
  elseif opattr hFile
	invoke SetFilePointerEx, hFile, 0, 0, edx, FILE_CURRENT	; 0, 0: should be one QWORD
  else
	tmp$ CATSTR <## Loc, line >, %@Line, <: #n or handle expected ##>
	% echo tmp$
	.err
  endif
  dec eax	; sign? if eax=0
  pop eax  
  pop edx
  pop ecx
  EXITM <eax>	; if Sign? then error
ENDM

; invoke SetFilePointer, MbFH[4*@SubStr(<file>, 2, 1)], offset, 0, FILE_BEGIN
Seek MACRO file, skbytes
LOCAL hasPlus, hasMinus, tmp$, ot, op1$
  hasPlus INSTR <skbytes>, <+>
  hasMinus INSTR <skbytes>, <->
  ifdif @SubStr(<file>, 1, 1), <#>
	echo *** expected: Seek #n, #bytes ***
	.err
  endif
  push ecx
  if hasPlus+hasMinus eq 1
	op1$ SUBSTR <skbytes>, 2
	push FILE_CURRENT	; rel: Seek #n, -eax
  else
	op1$ equ <skbytes>
	if hasPlus
		op1$ SUBSTR <skbytes>, 1, hasPlus-1
	endif
	if hasMinus
		op1$ SUBSTR <skbytes>, 1, hasMinus-1
	endif
	push FILE_BEGIN	; abs: Seek #n, eax-ecx or Seek #n, MyQword
  endif
  push 0	; no lpNewFilePointer
  if TYPE op1$ eq QWORD
	push dword ptr op1$[4]
	push dword ptr op1$
  elseif hasPlus
	push 0	; no qword
	push op1$
	if hasPlus gt 1
		add stack, dword ptr @SubStr(<skbytes>, hasPlus+1)	; e.g. ecx+eax
	endif
  elseif hasMinus
	if hasMinus gt 1
		push 0
		push op1$		; e.g. eax-ecx
		sub stack, dword ptr @SubStr(<skbytes>, hasMinus+1)
	else
		push -1
		push op1$
		neg stack
	endif
  else
	push 0
	push skbytes
  endif
  push MbFH[4*@SubStr(<file>, 2, 1)]	;; #BasFiles
  call SetFilePointerEx
  pop ecx
ENDM

MakeDir MACRO ptrPath	; .if Zero? then success, !Zero? for failure, eax is ptr to path
LOCAL NxtFile, @Err
	push repargA(ptrPath)	; you may use MakeDir "MyNewFolder"
	push esi
	push edi
	push ebx
	push ecx
	mov ebx, esp	; shortest solution
	sub esp, MAX_PATH	; create a buffer for the copy
	mov edi, esp	; edi points to buffer
	invoke lstrcpyA, edi, [ebx+4*4]	; src=pPath (this is the macro, no ret address!)
	xchg ecx, Len(edi)	; set counter for scasb
	push edi
	pop esi
NxtFile:	mov al, "\"
	repne scasb	; find the next backslash
	dec edi
	.if byte ptr [edi-1]!=":" && esi!=edi	; drives and leading \ should be ignored
		.if !ecx && [edi]!=al	; last element may or may not have backslash
			inc edi
		.endif
		mov byte ptr [edi], 0	; zero-delimit current path
		push ecx
		invoke GetFileAttributes, esi
		pop ecx
		.if eax==INVALID_FILE_ATTRIBUTES	; folder not found
			push ecx
			invoke CreateDirectory, esi, 0
			pop ecx
			test eax, eax
			je @Err
			mov al, FILE_ATTRIBUTE_DIRECTORY	; folder successfully created
		.endif
		and eax, FILE_ATTRIBUTE_DIRECTORY	; really a folder?
		je @Err
		mov byte ptr [edi], "\"	; restore full path
	.endif
	inc edi
	test ecx, ecx
	ja NxtFile
@Err:	mov esp, ebx
	pop ecx
	pop ebx
	pop edi
	pop esi
	cmp eax, FILE_ATTRIBUTE_DIRECTORY	; if Zero? then OK
	pop eax		; return the original path
ENDM

TouchFcs=0	; don't touch the file creation stamp, i.e. last write+access only
wToFlg=0
Touch MACRO fnu1:=<1>, chk:=<0>
LOCAL is, fnu, chkx$, tFlg, tmp$, tGsp
  tFlg=1
  tGsp=0
  if TouchFcs
	tFlg=0
  endif
  if usedeb
	tFlg=tFlg or 4
  endif
  chkx$ CATSTR <chk>, <___>
  chkx$ SUBSTR chkx$, 1, 3
  ifidn <#>, @SubStr(<fnu1>, 1, 1)
	fnu SUBSTR <fnu1>, 2, 1
  else
	fnu SUBSTR <fnu1>, 1, 1
  endif
  ifidni chkx$, <xmm>	; GfLastWrite(index)
	push tFlg or 2
	ifidn <fnu1>, emArr$
		push 0
		call MbGetSlotPointer
		tGsp=1
	endif
  else
	% is INSTR <chk>, <[Edx.>
	if is
		movlps xmm0, chk
		push tFlg or 2
	elseif (opattr chk) eq atImmediate
		push chk or tFlg
	else
		push chk
	endif
  endif
  is INSTR <0123456789>, fnu
  if is
	push MbFH[4*fnu]
  else
	Open10=1
	if wToFlg
		wToFlg=0
		if tGsp
			wOpen "U", #10, [edx]
		else
			wOpen "U", #10, fnu1
		endif
	else
		if tGsp
			Open "U", #10, [edx]
		else
			Open 55h, #10, fnu1	; U
		endif
	endif
	push MbFH[4*10]
  endif
  TouchP PROTO :DWORD, :DWORD
  call TouchP
  ife is
	Close #10	; the # is needed
  endif
ENDM
wTouch MACRO fnu1:=<1>, chk:=<0>
  wToFlg=1
  Touch fnu1, chk  
ENDM

NoTag$ MACRO pStr
  if @InStr(1, <pStr>, <Use_>)
  	push Cat$(pStr)
  else
  	PushString pStr
  endif
  NoTagP PROTO
  call NoTagP
  EXITM emArr$
ENDM
fr$Mode=1
wFileRead$ MACRO fname
  fr$Mode=3
  EXITM FileRead$(fname)
ENDM
frLine=0
frWeb=0
WM_DOWNLOADFINISHED equ WM_APP+765h
FileRead$ MACRO fname, xtras:VARARG		; cb:hStatic, msg:hWnd
Local is, xarg, aSync
  ExternDef MbD2m:DWORD
  aSync=0
  for xarg, <xtras>
	is INSTR <xarg>, <cb:>
	if is
		mov MbD2m[4], @SubStr(<xarg>, 4)
	endif
	is INSTR <xarg>, <msg:>
	if is
		m2m MbD2m[8], @SubStr(<xarg>, 5)
		aSync=1
	endif
	is INSTR <xarg>, <flags:>
	if is
		mov MbD2m[12], @SubStr(<xarg>, 6)
	endif
  endm
  if @Line eq frLine
	is INSTR <fname>, <://>
	ife is
		is INSTR <fname>, <www.>
	endif
	if is and (frWeb GT 0)
		.err <## FileRead$(): you cannot concat two web pages, split lines ##>
	endif
	frWeb=is
  endif
  frLine=@Line
  ifdifi <fname>, <eax>
	if @InStr(1,<fname>,<Use_>)
		tmp$ CATSTR <## line >, %@Line, <: not allowed ##>
		% echo tmp$
		.err
	else
		ifdef stLastID
			if stLastID eq 1
				ifidn emArr$, <fname>
					.err @CatStr(<## line >, %@Line, <: fr$(files$(n)) not possible, please split ##>)
				endif
			endif
		endif
		if fr$Mode and 2
			mov eax, repargW(fname)
		else
			mov eax, repargA(fname)
		endif
	endif
  endif
  if aSync
	fr$Mode=1
	push ecx
	push eax
	invoke CreateThread, 0, 0, FileReadP-5, eax, 0, esp
	pop edx
	pop ecx
	EXITM <>
  else
	invoke FileReadP, fr$Mode
	fr$Mode=1
	EXITM <Use_Let>
  endif
ENDM
Download MACRO url, args:VARARG	; url [, msg:hWnd] [, cb:callback]
  ifb <args>
	FileRead$(url, msg:hWnd)
  else
  	ife @InStr(1, <args>, <msg:>)
		FileRead$(url, args, msg:hWnd)
  	else
		FileRead$(url, args)
  	endif
  endif
ENDM
FileWrite MACRO fName0, pBuf0, bytes0:=<0>
LOCAL useX, useC, curSlot, fName, pBuf, bytes, xTmp$, fwsf_x
  fName equ <fName0>
  bytes equ <bytes0>
  ifidn <pBuf0>, <(eAx)>
	pBuf equ MbCat$
  else
	pBuf equ <pBuf0>
  endif
  if @InStr(1, <pBuf0>, <res:>)
	push ecx
	push ebx
	invoke FindResource, 0, @SubStr(<pBuf0>, 5), RT_RCDATA
	if usedeb
		test eax, eax
		.if Zero?
			xTmp$ CATSTR <"FileWrite, line >, %@Line, <: ">
			ifidni <Console>, @Environ(<oSusy>)
				Print xTmp$, Err$()
			else
				MsgBox 0, Err$(), xTmp$, MB_OK
			endif
			xor eax, eax
		.endif
	endif
	.if eax
		xchg eax, ebx		; hRes
		push rv(SizeofResource, 0, ebx)
		Open10=1
		Open "O", #10, fName
		invoke LoadResource, 0, ebx		; returns pointer to content in eax
		pop ecx
		push ecx
		PrintBuffer #10, eax, ecx
		Close #10
		pop edx
	.endif
	pop ebx
	pop ecx
	EXITM
  elseif @InStr(1, <pBuf0>, <stream:>)
	ifndef fwStream
		.DATA?
		fwStream EDITSTREAM <>
		.CODE
		.if 0	;; do NOT delete
			FwStreamOut::
			; proc cookie:DWORD,pBuffer:DWORD, NumBytes:DWORD, pBytesWritten:DWORD
			; pBytesWritten equ [esp+16][4]
			; NumBytes equ [esp+12][8]
			; pBuffer equ [esp+8][12]
			; cookie equ [esp+4][16]
			invoke WriteFile, [esp+20], [esp+20], [esp+20], [esp+20], 0
			xor al, 1
			retn 4*4
		.endif
	endif
	Open10=1
	Open "O", #10, fName
	mov fwStream.dwCookie, eax
	mov fwStream.pfnCallback, FwStreamOut
	if (opattr bytes0) eq atImmediate
		fwsf_x=SF_RTF	; no args
		if bytes0
			if (bytes0 and SF_UNICODE) eq SF_UNICODE
				Print #10, Chr$(0FFh, 0FEh)
			endif
			fwsf_x=bytes0
		endif
	else
		fwsf_x equ <bytes0>
		.if fwsf_x & SF_UNICODE
			Print #10, Chr$(0FFh, 0FEh)
		.endif
	endif
	push ecx
	invoke SendMessage, @SubStr(<pBuf0>, 8), EM_STREAMOUT, fwsf_x, addr fwStream
	Close #10	; return bytes written in edx
	pop ecx
	EXITM
  endif
  pushad			; pBuf could be eax or edx
  if @InStr(1, <pBuf0>, <+>)
	pBuf equ <#c>
  endif
  xTmp$ CATSTR <bytes0>, <__>
  xTmp$ SUBSTR xTmp$, 1, 3
  ifidni xTmp$, <xmm>
	bytes equ <0>
  endif
  useX INSTR pBuf, <Use_>
  ifidn pBuf, emArr$
	useX=1
  endif
  ifidn pBuf, <( EdX)>
	useX=1
  endif
  if useX
	ifidni fName, <esi>
		pBuf equ <edi>
	else
		pBuf equ <esi>
	endif
	bytes equ <ecx>	; get from slot
	push 0
	call MbGetSlotPointer	; get buffer
	mov pBuf, [edx]
	mov bytes, [edx+4]
  endif
  ifidn fName, <( EdX)>
	curSlot=1
  elseifidn fName, emArr$
	curSlot=0
  endif
  ifdef curSlot
	ifidn pBuf, <#c>
		% echo @CatStr(<## line >, %@Line, <: Use a non-volatile reg32 for the filename ##>)
		.err
	endif
	push -useX	; 0 or -1
	call MbGetSlotPointer
	mov eax, [edx]
	fName equ <edi>
	if curSlot
		mov fName, Utf8$([edx])
	else
		mov fName, [edx]
	endif
  endif
  Open10=1
  Open "O", #10, fName
  ifidn pBuf, <#c>
	pBuf equ Cat$(pBuf0)
	bytes equ <0>
  endif
  if @Line eq frLine
		ifdif <pBuf0>, <Use_Let>
			.err <## FileRead$(): split lines ##>
		endif
	push MbFH[4*10]	; save #10, mbrc uses it
	push 0	; no dest
	push 127
	push 0C0000001h
	call MbPrint
	pop MbFH[4*10]	; restore #10
	push eax	; otherwise heapfree problem
	PrintBuffer #10, eax, bytes
	call MbStringErase	; pop eax, Clr$ eax
  else
	Print #10:bytes, pBuf
  endif
  ifidni xTmp$, <xmm>
	sub esp, FILETIME
	mov eax, esp
	movlps qword ptr [eax], xmm0
	if TouchFcs
		xTmp$ equ <eax>
	else
		xTmp$ equ <0>
	endif
	invoke SetFileTime, MbFH[9*DWORD], xTmp$, eax, eax 	; Touch #10
	add esp, FILETIME
  endif
  popad
  Close #10		; returns Lof in edx
ENDM
; Zip & UnZip Macros
MbZipDefs =	0	; not yet initialised
MbZipLog =	0
MbZipTimeOut =	999999
; FreeArc: Windows installer
MbUnZipExeDef$ equ	<%ProgramFiles%\FreeArc\bin\Arc.exe -dp#d# x #a#>
MbZipExeDef$ equ	<%ProgramFiles%\FreeArc\bin\Arc.exe create -mx #a# @>
MbZipLog = 1
MbZipInit macro
LOCAL tmp$
  ife MbZipDefs
	MbZipDefs = 1
	.DATA
	tmp$ CATSTR <txZipExe db ">, MbZipExeDef$, <">
	tmp$
	txZipTmp db "~MbToZip.lst", 0	; contains the files to zip
	txZipBackSlash db "\", 0
	tmp$ CATSTR <txUnZipExe db ">, MbUnZipExeDef$, <", 0>
	tmp$
	.DATA?
	ZipFilesArchived	dd ?
	txZipCmdLine	dd 70 dup(?)	; 280 bytes
	.CODE
  endif
ENDM
ZipFiles MACRO archive, ct:=<-1>, consSW:=<SW_MINIMIZE>, consNew
  MbZipInit
  ifidn <ct>, <0>
	Store offset txZipTmp, Files$()	; write all non-empty strings to file
  else
	Store offset txZipTmp, Files$(), ct	; write ct strings to file
  endif
  .if eax
	push esi
	push edi
	push eax	; #files to be archived
	mov edi, offset txZipCmdLine
	invoke ExpandEnvironmentStrings, Cat$(Replace$(offset txZipExe, "#a#", &archive&)), edi, 260
	ExternDef LastGetFilesPath:DWORD
	mov esi, offset LastGetFilesPath
	dec Rinstr(esi, offset txZipBackSlash)
	.if Sign?
		inc edx	;  adc edx, 0 would be nice but dec does not alter the CF
	.endif
	mov byte ptr [esi+edx], 0
	Let edi=Replace$(edi, "#d#", esi)
	if MbZipLog
		Open "A", #8, "~ZipLog.txt"
		PrintLine #8, edi
		Close #8
	endif
	Launch edi, consSW, MbZipTimeOut, consNew
	.if eax<=32
		Clr stack
	.endif
	pop eax
	pop edi
	pop esi
  .endif
  mov ZipFilesArchived, eax
ENDM
UnZipFiles MACRO archive, where:=<0>, consSW:=<SW_MINIMIZE>, consNew
  MbZipInit
  push esi
  push edi
  mov edi, offset txZipCmdLine
  invoke ExpandEnvironmentStrings, Cat$(Replace$(offset txUnZipExe, "#a#", &archive&)), edi, 200
  ifidn <where>, <0>
	mov esi, offset txZipBackSlash
  else
	mov esi, repargA(where)
  endif
  Let edi=Replace$(edi, "#d#", esi)
  if MbZipLog
	Open "A", #8, "~ZipLog.txt"
	PrintLine #8, edi
	Close #8
  endif
  Launch edi, SW_MINIMIZE, MbZipTimeOut, consNew
  pop edi
  pop esi
ENDM
; ### new unzip macros, do not require FreeArc ###
Uzi=0
UziWarn=0
UnzipInit MACRO fname
  ifndef MbInit
	.err <## UnzipInit requires MasmBasic Init ##>
  endif
  MbUZ PROTO :DWORD, :DWORD
  ife UziWarn
	UziWarn=1
	ifdifi @Environ(oBody), <MasmBasic>
		echo ## UnzipInit: debug needs JWasm + linkv10 ##
	endif
  endif
  if (opattr fname) eq atImmediate
	if fname LE 127
		push fname
	else
		push repargA(fname)
	endif
  else	
	push repargA(fname)
  endif
  push -1
  call MbUZ
  Uzi=1
ENDM
UnzipFile MACRO inx, baseDir:=<0>
  ifidn <baseDir>, <0>
	push 0
  else
	push repargA(baseDir)	; fname
  endif
  push inx
  call MbUZ
  ExternDef xzmb:DWORD
  UnzipFileLen equ xzmb[12]
  ifidn <baseDir>, <0>
	EXITM <Use_mov_z$_Left$>
  elseifidn <baseDir>, <$>
	EXITM <eax>
  else
	EXITM <>
  endif
ENDM
UnzipExit MACRO
  push eax
  push -2
  call MbUZ
  Uzi=0
ENDM
ifdeb MACRO args:VARARG
if usedeb
	args
endif
ENDM
; deb must come after Print, Open, Lof etc
; ** MasmBasic debug macro **
; WndProc proc ...
;   inc msgCount
;   .if debMsg()
; 	deb 4, "msg", chg:msgCount	; will only be shown if chg:xxx has changed
;   .endif
NoDebMsg equ <WM_MOUSEMOVE, WM_NCHITTEST, WM_SETCURSOR, WM_GETICON, WM_NCMOUSEMOVE, WM_MOVING>
.DATA?
	dd ?		; extra for wm_notify
debChg	dd 2*6 dup(?)	; 0 flag, 5 macs max
msgCount	dd ?
debChgCt	= 0		; 0 reserved
debChgMsg	equ <uMsg>

.CONST
StdOutLimit equ <62600>		; Win7 limit, do not increase (->StringFill)
debExpand=0		; 0=use short args
MB_deb=MB_OKCANCEL or MB_SETFOREGROUND or MB_TOPMOST
usedebI3=0		; force an INT 3
; version 26.12.16, flags/FLAGS, x:/d:/u:/b: (i:, s: treated as signed); $$widestring
deb MACRO slot:REQ, debtitle:REQ, args:VARARG
LOCAL txt_title, ctarg, stx, xmx, oa, mchg, argChg, arg1, tmp$, NoMsg, wm$, isL, isR, ndbLen, c1$, c1w, debNC
  if usedeb
  txt_title equ repargA(<debtitle>)
  mov EspGlob, esp	;; borrowed from ClearLocalsP, search deb*esp to find your uses
  pushfd		; ->popfd
  pushad
  push eax
  cld
  fsave MbDebugBuffer	;; save FPU regs
  frstor MbDebugBuffer	;; and restore them, because fsave clears the FPU
  mov eax, offset MbDebugBuffer+160	;; Str$ preserves all xmm regs, but a MsgBox might trash them...
  movups [eax], xmm0
  movups [eax+16], xmm1
  movups [eax+32], xmm2
  movups [eax+48], xmm3
  movups [eax+64], xmm4
  movups [eax+80], xmm5
  movups [eax+96], xmm6
  movups [eax+112], xmm7
  pop eax
  ctarg = 0
  mchg = 0
  mov MbDebugBuffer[160+16*8], 0	;; empty the buffer (first 160 reserved for FPU, 108 needed for 486, plus 8*16 for xmm)
  is INSTR sDim$, @CatStr(<@>, %@Line, <#>)
  if is
	sDim$ SUBSTR sDim$, is
  endif
  For arg, <args>
	LOCAL da$, arg2, flagShow, bydisp, is, is1, is2, nustr, cc, fcX, fcB, fcD, fcU, arrL$, arrR$, argsize
	bydisp equ <800>
	ctarg = ctarg+1
	flagShow = 1
	xmx INSTR <arg>, <Xmm>			; mixed case: xmm as integer
	ife xmx
		xmx INSTR <arg>, <xmm>		; lowercase: xmm as real
	endif
	pushad
	.DATA
	tmp$ equ <arg>
	is INSTR tmp$, <ptr [Edx>
	if debExpand
		tmp$ CATSTR <nustr db ">, tmp$, <", 0>
		tmp$
	elseif is
		is2 INSTR sDim$, <#>
		if is2
			sDim$ SUBSTR sDim$, is2+1
			is1 INSTR sDim$, </>
			arrL$ SUBSTR sDim$, 1, is1-1
			is2 INSTR sDim$, <@>
			arrR$ SUBSTR sDim$, is1+1, is2-is1-1
			sDim$ SUBSTR sDim$, is2
			tmp$ CATSTR <nustr db ">, arrL$, <", 40, ">, arrR$, <", 41, 0>
			tmp$
		endif
	else
		nustr db "&arg&", 0
	endif
	da$ equ <offset nustr>
	argsize = SIZEOF nustr
	.CODE
	fcX INSTR <arg>, <x:>					;; force display as hex?
	fcB INSTR <arg>, <b:>					;; force bin?
	fcD INSTR <arg>, <d:>					;; force dec?
	fcU INSTR <arg>, <u:>					;; force unsigned dec?
	mchg INSTR <arg>, <chg:>			;; monitor this arg for changes?
	if mchg
  		arg2 SUBSTR <arg>, mchg+4
  		argChg SUBSTR <arg>, mchg+4		; the arg we need to watch
	elseif fcX
  		arg2 SUBSTR <arg>, fcX+2
	elseif fcB
  		arg2 SUBSTR <arg>, fcB+2
	elseif fcD
  		arg2 SUBSTR <arg>, fcD+2
	elseif fcU
  		arg2 SUBSTR <arg>, fcU+2
	else
		if usedeb eq 16
			fcX=1
		endif
		if usedeb eq 2
			fcB=1
		endif
		is INSTR <arg>, <:>
		if is eq 2
			arg2 SUBSTR <arg>, 3
		else
	  		arg2 equ <arg>
		endif
	endif
	stx INSTR arg2, <ST>				; FPU register?
	if fcB
		if xmx
			xmx=0
			movd eax, arg2
			arg2 equ <eax>
		elseif stx eq 1
			stx=0
			push eax
			fxch arg2
			fist dword ptr [esp]
			fxch arg2
			pop eax
			arg2 equ <eax>
		endif
	endif
	if xmx									; display XMM register
		invoke lstrcatA, MbDebugPtr, da$
		if fcX
			invoke lstrcatA, MbDebugPtr, Chr$(9, 9)
			invoke lstrcatA, MbDebugPtr, Hex$(arg2)
		else
			is INSTR <arg>, <f:>
			if is eq 1
				invoke lstrcatA, MbDebugPtr, Str$("\t\t%Gf", arg) 	; float with real8 precision, two tabs
			elseif fcU
				invoke lstrcatA, MbDebugPtr, Str$("\t\t%u", arg2)		; signed integer, two tabs, xmm is short
			else
				invoke lstrcatA, MbDebugPtr, Str$("\t\t%i", arg2)		; integer, two tabs, xmm is short
			endif
		endif
	elseif stx eq 1						; FPU as Real10
		invoke lstrcatA, MbDebugPtr, da$
		if fcX
			invoke lstrcatA, MbDebugPtr, Chr$(9, 9)
			invoke lstrcatA, MbDebugPtr, Hex$(arg2)
		else
			fxch arg
			fstp MbDebugR10
			fld MbDebugR10
			fxch arg
			invoke lstrcatA, MbDebugPtr, Str$("\t\t%Jf",MbDebugR10)	; display with full precision & two tabs, ST() is short
		endif
	elseifidni <arg>, <flags>
		mov esi, MbDebugPtr
		.Repeat
			lodsb
		.Until !al
		mov edi, esi
		dec edi
		ifndef debfl$
			.DATA
			debFL$ db "FLAGS:", 9, 9, "CrPrArZSTIDO", 0	; UPPERCASE: all
			debfl$ db "flags:", 9, 9, "CrrrrrZSrrrO", 0	; lowercase: only important ones
			.CODE
		endif
		ifidn <arg>, <FLAGS>
			mov esi, offset debFL$
		else
			mov esi, offset debfl$
		endif
		mov ecx, [esp+2*32]
		movsd
		movsd
		.While 1
			lodsb
			.Break .if !al
			ror ecx, 1
			.if !Carry?
				or al, 32
			.endif
			.if al!="r"
				stosb
			.endif
		.Endw
		stosb
		dec edi

	elseifidn <arg>, <CarrY?>	; Flags()
	  	if ctarg gt 1
	  		tmp$ CATSTR <## deb: Flags must be first argument in line >, %@Line, < ##>
	  		% echo tmp$
		  	.err
		endif
	  	.if Carry?
	  		tmp$ CATSTR <invoke lstrcatA, MbDebugPtr, aChr$("Flags(>, LastFlag, <)", 9, "True")>
			tmp$
	  	.else
	  		tmp$ CATSTR <invoke lstrcatA, MbDebugPtr, aChr$("Flags(>, LastFlag, <)", 9, "False")>
			tmp$
	  	.endif
	else										; all other cases
		pushad
		invoke lstrcatA, MbDebugPtr, da$
		invoke lstrcatA, MbDebugPtr, Tb$
		if argsize le 8
			invoke lstrcatA, MbDebugPtr, Tb$
		endif
		popad
		c1w=0
		cc INSTR <arg>, <$>			;; display as string?
		if cc eq 1
			c1$ SUBSTR <arg>, 2, 1
			ifidn c1$, <$>
				c1w=1
			endif
			arg2 SUBSTR <arg>, 2+c1w
			oa INSTR arg2, <:>
			if oa
				bydisp SUBSTR arg2, oa+1
				if (opattr bydisp) eq atImmediate
					if c1w
						c1w=2*bydisp
						bydisp equ c1w
					endif
					if bydisp gt 53200
						if bydisp gt StdOutLimit
							bydisp equ StdOutLimit
						endif
						tmp$ CATSTR <## line >, %@Line, <: deb display limited to >, %bydisp, < bytes (XP limit i>, <s 53200) ##>
						% echo tmp$
					endif
				endif
				arg2 SUBSTR arg2, 1, oa-1
			endif
		endif
		if ((opattr arg2) eq atRegister) and (@SizeStr(arg2) lt 3)		; check if word or byte register
			movzx esi, arg2		; $ax should trigger an error
		else
			stx INSTR arg2, <[esp>
			if stx
				mov esi, EspGlob			; esi replaces esp
				arg3 SUBSTR arg2, stx+4
				arg3 CATSTR <[esi>, arg3
				mov esi, arg3
			else
				ifidn arg2, emArr$
					xchg esi, eax			;; a slot
				else
					is INSTR arg2, <].>	;; [esi.RECT+4*ecx-0].left
					if is
						is1 INSTR 2, arg2, <+>
						is2 INSTR 2, arg2, <->
						if is1
							if (is1 lt is2) or (is2 eq 0)
								is2=is1
							endif
						endif
						arg3 SUBSTR arg2, is+1
						if is2
							arg1 SUBSTR arg2, 1, is2-1
							tmp$ SUBSTR arg2, is2, is-is2
							arg2 CATSTR arg1, arg3, tmp$, <]>		; [esi.RECT.left+4*ecx-0]
						else
							arg1 SUBSTR arg2, 1, is-1
							arg2 CATSTR arg1, arg3, <]>
						endif
					endif
					stx = ChkNum(arg2)	;; expansion??
					if stx eq MbDword
						is INSTR aPass$, <p:>	; wp: or bp: flags for word ptr and byte ptr
						if is eq 2
							is INSTR aPass$, <bp:>	; byte?
							if fcX
								invoke lstrcatA, MbDebugPtr, Hex$(arg2)
							elseif fcB
								movzx esi, arg2
								mov eax, Bin$(esi)
								if is
									add eax, 24
								else
									add eax, 16
								endif
								invoke lstrcatA, MbDebugPtr, eax
							elseif fcU
								invoke lstrcatA, MbDebugPtr, Str$("%u", arg2)
							else
								invoke lstrcatA, MbDebugPtr, Str$(arg2)
							endif
							flagShow = 0
						elseifidni arg2, <esp>
							mov esi, EspGlob
						else
							mov esi, arg2
						endif
					elseif stx eq MbQword
							if fcX
								invoke lstrcatA, MbDebugPtr, Hex$(arg2)
							elseif fcU
								invoke lstrcatA, MbDebugPtr, Str$("%u", arg2)
							else
								invoke lstrcatA, MbDebugPtr, Str$(arg2)
							endif
						flagShow = 0
					elseif (stx eq MbReal4) or (stx eq MbReal8) or (stx eq MbReal10)
						ffree st(7)
						if fcX
							invoke lstrcatA, MbDebugPtr, Hex$(arg2)
						else
							@CatStr(<fld >, arg2)
							fstp MbDebugR10
							tmp$ CATSTR <invoke lstrcatA, MbDebugPtr, Str$("%>, @SubStr(<7GJ>, stx, 1), <f",MbDebugR10)>
							tmp$
						endif
						flagShow = 0
					endif
				endif
			endif
		endif
		if cc eq 1
			.if signed esi<=127 || signed esi<=-128
				if fcX
					invoke lstrcatA, MbDebugPtr, Hex$(arg2)
				elseif fcB
					invoke lstrcatA, MbDebugPtr, Bin$(esi)
				else
					invoke lstrcatA, MbDebugPtr, str$(esi)
				endif
				invoke lstrcatA, MbDebugPtr, Tb$
				if c1w
					mov esi, wChr$(offset MbDebugNotPointer)
				else
					mov esi, offset MbDebugNotPointer
				endif
			.endif
			mov edi, MbDebugPtr
			add edi, Len(edi)
			if c1w
			if usedebI3
				usedebI3=0
				INT 3
			endif
				add wLen(esi), eax
				inc eax
			else
				void Len(esi)
			endif
			.if eax>bydisp
				mov eax, bydisp
			.endif
			push eax
			inc eax
			invoke MbCopy, edi, esi, eax		; either string or "not a pointer", max 800 bytes of 1024
			if c1w
				pushad
			push edi
			MbUtf8 PROTO
			call MbUtf8		; under MbPrint; see also RecallP
			xchg eax, ecx
			inc wLen(ecx)
			add eax, eax
			.if eax>=bydisp
				m2m eax, bydisp
			.endif
			invoke MbCopy, edi, ecx, eax
			and dword ptr [eax], 0
				popad
			endif
			pop eax
			.if eax>=bydisp
				mov dword ptr [edi+eax],  ".. "	; in case the string is longer...
			.endif
		elseif flagShow
			if fcX
				ifidni arg2, <esp>
					invoke lstrcatA, MbDebugPtr, Hex$(EspGlob)
				else
					invoke lstrcatA, MbDebugPtr, Hex$(esi)
				endif
			elseif fcB
				invoke lstrcatA, MbDebugPtr, Bin$(esi)
			else
				invoke lstrcatA, MbDebugPtr, str$(esi)
			endif
		endif
	endif
	if (ctarg eq 1) and mchg
		invoke lstrcatA, MbDebugPtr, Tb$	; dense format
	else
		invoke lstrcatA, MbDebugPtr, CrLf$	; ready for next arg
	endif
	popad
	ENDM			; end For
	ifdef argChg
	debChgCt = debChgCt+1	; next slot - #0+1 reserved for Recall & ct flag
	.if debChg==0
		pushad
		mov ecx, Chr$("\masm32\MasmBasic\Res\WM_Names.txt")
		mov esi, Chr$("\masm32\MasmBasic\Res\Wm_Keys.dat")
		.if !Exist(ecx)
			add ecx, 22	; WM_Names.txt
			add esi, 22	; WM_Keys.dat
		.endif
		Recall ecx, MbDebChg$()
		Let debChg=FileRead$(esi)	; debChg[12] is WM_NULL
		popad
	.endif
		isR INSTR NoDebMsg, <,>	; want this msg?
		isL=1
		ndbLen SIZESTR NoDebMsg
		mov eax, uMsg
		% echo ## deb: excluded NoDebMsg ##
		While ndbLen
			isR INSTR isL, NoDebMsg, <,>
			ife isR
				isR=ndbLen+1
				ndbLen=0
			endif
			wm$ SUBSTR NoDebMsg, isL, isR-isL
			cmp eax, wm$
			je NoMsg
			isL=isR+1
		ENDM
	mov eax, debChgMsg	; uMsg: current msg...
	.if eax==WM_NOTIFY
		mov edx, lParam
		mov edx, [edx.NMHDR.code]
		mov debChg[-4], edx
	.endif
		is INSTR aPass$, <p:>
		if is
		movzx edx, argChg
	else
		mov edx, argChg
	endif
	xchg eax, debChg[8*debChgCt+4]	; ... exchanged with old one
	cmp edx, debChg[8*debChgCt]
		NoMsg:
	.if !Zero?
		mov debChg[8*debChgCt], edx
		push eax
		tmp$ CATSTR <invoke lstrcatA, MbDebugPtr, Chr$(">, debChgMsg, < = ")>
		tmp$	; uMsg = WM_...
		if (opattr debChgMsg) eq atRegister
			pop eax
				if fcU
				invoke lstrcatA, MbDebugPtr, Str$("%u", eax)
			else
				invoke lstrcatA, MbDebugPtr, Str$("%i", eax)
			endif
		else
			mov ecx, MbDebChg$(?)	; # of elements
			pop eax
			push ecx
			mov edi, debChg
			repne scasd
			pop edx
			push eax
			.if Zero?
				sub edx, ecx
				dec edx
				push MbDebChg$(edx)
			.else
				push Hex$(eax)
			.endif
			push MbDebugPtr
			call lstrcatA
			pop eax
			.if eax==WM_NOTIFY
				mov ecx, debChg[-4]
				ifndef debNCodes
						.DATA
						debNCodes LABEL BYTE
						db ": NM_OUTOFMEMORY", 0
						db ": NM_CLICK", 0
						db ": NM_DBLCLK", 0
						db ": NM_RETURN", 0
						db ": NM_RCLICK", 0
						db ": NM_RDBLCLK", 0
						db ": NM_SETFOCUS", 0
						db ": NM_KILLFOCUS", 0
						db ": NM_CUSTOMDRAW", 0
						db ": NM_HOVER", 0
						db ": NM_NCHITTEST", 0
						db ": NM_KEYDOWN", 0
						db ": NM_RELEASEDCAPTURE", 0
						db ": NM_SETCURSOR", 0
						db ": NM_CHAR", 0
						db ": NM_TOOLTIPSCREATED", 0
						db ": NM_LDOWN", 0
						db ": NM_RDOWN", 0
						db ": NM_THEMECHANGED", 0
						debNttnShow db ": TTN_SHOW", 0
						debNttnPop	db ": TTN_POP", 0
						debNttnNeedTextA	db ": TTN_NEEDTEXTA", 0
						debNttnNeedTextW	db ": TTN_NEEDTEXTW", 0
						.CODE
				endif
					.if signed ecx<0 && signed ecx>=-22
						push esi
						mov esi, offset debNCodes
						.While 1
							inc ecx
							.Break .if !Sign?
							.Repeat
								lodsb
							.Until !al
						.Endw
						xchg eax, esi
						pop esi
						debNC:
						invoke lstrcatA, MbDebugPtr, eax
					.elseif ecx==TTN_SHOW
						mov eax, offset debNttnShow
						jmp debNC
					.elseif ecx==TTN_POP
						mov eax, offset debNttnPop
						jmp debNC
					.elseif ecx==TTN_NEEDTEXTA
						mov eax, offset debNttnNeedTextA
						jmp debNC
					.elseif ecx==TTN_NEEDTEXTW
						mov eax, offset debNttnNeedTextW
						jmp debNC
					.else
						invoke lstrcatA, MbDebugPtr, Str$(": %i", ecx)
					.endif
			.endif
			invoke lstrcatA, MbDebugPtr, Chr$("      ")	; ready for next arg
		endif
		invoke lstrcatA, MbDebugPtr, CrLf$	; ready for next arg
	endif
  if slot eq 5		; deb 5, "Test", eax
	push rv(GetLastError)	; save error
	nops 4
  	Open "A", #8, DebFile$	; caution: deb 5 uses MbPrint
	inc MbDebugLine
	Print #8, str$(MbDebugLine), Tb$
	if ctarg eq 1
		tmp$ CATSTR <Print #8, >, txt_title, <, Tb$>
	else
		tmp$ CATSTR <Print #8, >, txt_title, <, CrLf$>
	endif
	tmp$
	Print #8, MbDebugPtr
	Close #8
	nops 4
	call SetLastError			; restore error
  elseif slot ge 4
	if slot eq 4
		mov MbDebugStop[4*4], IDOK
	else
	  	.if MbDebugStop[4*4]==IDOK
			mov MbDebugStop[4*4], IDOK+slot+1
		.endif
		.if sdword ptr MbDebugStop[4*4]>IDOK+1
	endif
	if ctarg eq 1
			aPrint &debtitle&, 9
			aPrint MbDebugPtr
	else
			if ctarg
				aPrint CrLf$		;; multi-arg has a leading CrLf, single-arg not
			endif
		nops 3
			aPrint &debtitle&, 13, 10
			aPrint MbDebugPtr
	endif
	if slot gt 4
			dec MbDebugStop[4*4]
		.endif
	endif
  else
  	.if MbDebugStop[4*slot]==IDOK
		mov MbDebugStop[4*slot], IDCANCEL
		ife ctarg
			invoke MessageBoxA, 0, txt_title, offset MbDebugTitle, MB_deb	;; deb "This is a text"
		else
			invoke MessageBoxA, 0, MbDebugPtr, txt_title, MB_deb		;; deb "This is a text", eax, edi$
		endif
		mov MbDebugStop[4*slot], eax
	.endif
  endif
  ifdef argChg
	.endif
  endif
  frstor MbDebugBuffer	;; get FPU regs back
  mov eax, offset MbDebugBuffer+160	;; Str$ preserves all xmm regs, but a MsgBox might trash them...
  movups xmm0, [eax]
  movups xmm1, [eax+16]
  movups xmm2, [eax+32]
  movups xmm3, [eax+48]
  movups xmm4, [eax+64]
  movups xmm5, [eax+80]
  movups xmm6, [eax+96]
  movups xmm7, [eax+112]
  popad
  popfd	; ->pushfd
  endif
ENDM
; --------- end deb -------
fdeb MACRO args:VARARG	; force deb
  olddeb=usedeb
  usedeb=1
  deb args
  usedeb=olddeb
ENDM
Err$ MACRO eMode, eTxt0	; 0: show always, 1: show if error, (): .if e$() [, optional text - use L for line number]
LOCAL eTxt
  push ecx
  push ebx
  MbXms
  invoke GetLastError
  xchg eax, ebx
  mov edx, offset MbDebugBuffer+512	; 1024/2
  push edx		; make a copy for the retval
  xor ecx, ecx
  push ecx		; no args
  push 512		; size
  push edx		; pBuffer
  push ecx		; default language
  push ebx		; the error #
  push ecx		; no source, GetItFromSystem
  push FORMAT_MESSAGE_FROM_SYSTEM
  call FormatMessage
  ifnb <eMode>
	mov eax, [esp]	; MbGpBuffer
	ifnb <eTxt0>
		ifidni <eTxt0>, <L>
			eTxt CATSTR <Chr$("Error in line >, %@Line, <:")>
		else
			eTxt equ repargA(<eTxt0>)
		endif
	else
		eTxt equ <0>
	endif
	ifidn <eMode>, <0>
		.if ebx
			invoke MessageBox, 0, eax, eTxt, MB_OK
		.endif
	else
		invoke MessageBox, 0, eax, eTxt, MB_OK
	endif
  endif
  MbXmr
  pop eax			; offset MbGpBuffer
  test ebx, ebx		; allows void Err$(), .if !Zero?
  pop ebx
  pop ecx
  ifnb <eMode>
	EXITM <>
  else
	EXITM <eax>
  endif
ENDM

mbx macro arg	; --------------- helper macro for message boxes ---------------
LOCAL is
  is INSTR <arg>, <( Edx)>
  ife is
	is INSTR <arg>, <( eAx)>
  endif
  ife is
	is INSTR <arg>, emArr$
  endif
  exitm %is  
ENDM
MsgBox MACRO dlg:REQ, text:REQ, title:REQ, style:=<MB_OK or MB_SETFOREGROUND>
  MbXms
  ifdif <dlg>, <0>
	ifdif <dlg>, <NULL>
		if @InStr(1, <dlg>, <h>) ne 1
			echo
			echo XXXX       MsgBox 0 or hWnd, "TEXT", "TITLE" [, MB_??]       XXXX
			echo
			.err
		endif
	endif
  endif
  push ecx
  push style
  push repargA(title)
  if mbx(text)
	if mbx(title)
		push -1
	else
		push 0
	endif
	call MbGetSlotPointer
	push [edx]
  else
	push repargA(text)
  endif
  push dlg
  call MessageBoxA
  MbXmr
  pop ecx
ENDM
;; usage: wMsgBox 0, "Text", wChr$("Title"), MB_YESNO
u82w=0	; UTF-8 to wide
wMsgBox MACRO dlg:REQ, text:REQ, title:REQ, style:=<MB_OK or MB_SETFOREGROUND>
LOCAL isx, ist
  MbXms
  ifdif <dlg>, <0>
	ifdif <dlg>, <NULL>
		if @InStr(1, <dlg>, <h>) ne 1
			echo
			echo XXXX       wMsgBox 0 or hWnd, "TEXT", "TITLE" [, MB_??]       XXXX
			echo
			.err
		endif
	endif
  endif
  push ecx
  push style
  if u82w
	push repargA(title)
	call MbwRec			; uft8->unicode
	push eax
  else
	push repargW(title)
  endif
  if mbx(text)
	if mbx(title)
		push -1
	else
		push 0
	endif
	call MbGetSlotPointer
	push [edx]
	if u82w
		call MbwRec
		push eax
	endif
  elseif u82w
	push repargA(text)
	call MbwRec
	push eax
  else
	push repargW(text)
  endif
  u82w=0
  push dlg
  call MessageBoxW
  pop ecx
  MbXmr
ENDM
uMsgBox MACRO args:VARARG
  u82w=1
  wMsgBox args
ENDM
uAlert MACRO txt$, title$, mbx
  u82w=1
  wMsgBox 0, cfm$(txt$), title$, mbx or MB_TASKMODAL
  EXITM <eax>
ENDM
Alert MACRO txt$, title$, mbx
  MsgBox 0, cfm$(txt$), title$, mbx or MB_TASKMODAL
  EXITM <eax>
ENDM

MsgMonitor macro
LOCAL mmlbl1, mmlbl2
  ifndef MbMsgEdi$
  .DATA?
	MbMsgEdi$	dd ?
	MbMsgCt	dd ?
	MbMsgLine	dd ?
	MbMsgTi	dd ?
  .CODE
  endif
	push edi
	push ecx
	push edx
	push eax
mmlbl1:
	mov edi, MbMsgEdi$
	test edi, edi
	jne mmlbl2
	Let MbMsgEdi$=FileRead$("\Masm32\RichMasm\Res\Wm_Keys.dat")
	mov ecx, LastFileSize
	sar ecx, 2
	mov MbMsgCt, ecx
	Recall "\Masm32\RichMasm\Res\Wm_Names.txt", WM_Names$()
	Open "O", #7, "Messages.txt"
	MacLineTimer=0
	mov MbMsgTi, Timer
	jmp mmlbl1

mmlbl2:	mov eax, uMsg
	mov ecx, MbMsgCt
	push ecx
	repne scasd
	pop edx
	sub edx, ecx
	xchg ecx, edx
	dec ecx
	.if !Sign?
		MacLineTimer=1
		sub Timer, MbMsgTi
		inc MbMsgLine
		PrintLine #7, Str$("%i\t", eax), Str$("%i\t", MbMsgLine), WM_Names$(ecx), Tb$, " &msgWhere&"
	.else
		PrintLine #7, Str$(ecx), " is foul"
	.endif
	pop eax
	pop edx
	pop ecx
	pop edi
ENDM

MbDllCt =	4	; slots 0+1 reserved for RichEdit
DllRTE =	1	; 1=throw a runtime error, 0=return zero in eax in case of error
DecRTE =	1
Dll MACRO name
LOCAL isL, isR
  isL INSTR <name>, <%>
  isR INSTR isL+1, <name>, <%\>
  push ecx
  if (isR gt isL) and isL
	push ExpandEnv$(repargA(name))
  else
	push repargA(name)
  endif
  pop eax
  push eax
  push eax
  call LoadLibrary
  pop edx	; name of DLL
  pop ecx
  if DllRTE
	if MbUseErrLine
		mov MbErrLine, @Line
	endif
	ExternDef MbError0:NEAR
	test eax, eax
	je MbError0-6	; MbError0a
  endif
  MbDllCt = MbDllCt + 4
  mov DllTable[MbDllCt], eax
ENDM

FreeDll MACRO num
  push ecx
  invoke FreeLibrary, DllTable[4*MbHash(num)]
  pop ecx
  and DllTable[4*MbHash(num)], 0
ENDM

Externdef MbRegs32:DWORD
MbEbp4VB equ <MbRegs32[-4]>
VbDll MACRO arg
  ifidni <arg>, <frameless>
	push eax
	mov MbEbp4VB, esp
	pop eax
  else
	mov MbEbp4VB, ebp
  endif
ENDM

;  mov CreateInvoke(zebox1, 4*dword), MessageBox
;  invoke zebox1, 0, Chr$("Text"), Chr$("Title"), MB_OK
;  mov CreateInvoke(zebox2, dword, :Dword, dWord, :DWORD), MessageBox
;  invoke zebox2, 0, Chr$("Text"), Chr$("Title"), MB_OK
ciMacCt=0
ciIsC=0
CreateInvokeC MACRO ciPtr, args:VARARG
  ciIsC=1
  EXITM CreateInvoke(ciPtr, args)
ENDM
CreateInvoke MACRO ciPtr, args:VARARG
LOCAL ciTd$, ciColon, ciStar, ciProto
  ciMacCt=ciMacCt+1
  ciProto CATSTR <ciPtr>, <_proto>, %ciMacCt
  ciTd$ CATSTR ciProto, < typedef PROTO>
  if ciIsC
	ciTd$ CATSTR ciTd$, < C>
	ciIsC=0
  endif
  FOR arg, <args>
  	ciStar INSTR <arg>, <*>
  	if (ciStar ge 2) and (ciStar le 4)		; short form, e.g. 5*DWORD
  		REPEAT @SubStr(<arg>, 1, ciStar-1)
	  		ciTd$ CATSTR ciTd$, <, :>, @SubStr(<arg>, ciStar+1)
	  	ENDM
	else
	  	ciColon INSTR <arg>, <:>
		ciTd$ CATSTR ciTd$, <, :>, @SubStr(<arg>, ciColon+1)
	  endif
  ENDM
  ciTd$
  .DATA?
  @CatStr(<DefProTDP>, %ciMacCt,< typedef ptr >, ciProto)
  ciPtr @CatStr(<DefProTDP>, %ciMacCt, < ?>)
  .CODE
  EXITM <ciPtr>
ENDM

MbHash macro fnu:REQ
  ifidn @SubStr(<fnu>, 1, 1), <#>
	EXITM @SubStr(<fnu>, 2)
  else
	EXITM <fnu>
  endif
ENDM

ImportC MACRO icName, icArgs:=<0>
LOCAL icTd$, icDeco$
if 0	; usage:
	ImportC jjSum, 2	; in PROTO section, sums up two args, x+y
	...
	invoke jjSum, 25, 35
	Print Str$("25+35=    \t%i\n", eax)
	; C++ source:
	extern "C"
	int _stdcall jjSum(int x , int y)
	{
	return(x+y);
	}
endif
  ifndef icNum
	icNum=0	;; start numbering
  endif
  icNum=icNum+1
  icDeco$ CATSTR <_>, <icName>, <@>, %(icArgs*4)
  @CatStr(icDeco$, < PROTO SYSCALL>)
  icTd$ CATSTR <icCall>, %icNum, < TYPEDEF PROTO >
  if icArgs
	icTd$ CATSTR icTd$, <:DWORD>
	REPEAT icArgs-1
		icTd$ CATSTR icTd$, <,:DWORD>
	ENDM
  endif
  icTd$
  icName CATSTR <icCall>, %icNum, < PTR >, icDeco$
ENDM

CodeSize MACRO algo, mode
  pushad
  mov eax, offset &algo&_endp
  sub eax, offset &algo&_s	; sub eax, offset algo sounds good but no good with symbols!
  ifidn <mode>, <1>
	invoke MessageBox, 0, Str$("%i bytes for &algo&", eax), Chr$("CodeSize:"), MB_OK
  elseifndef MbBufferGet
	aPrint str$(eax), 9, " bytes for &algo&", 13, 10
  elseifidn <mode>, <0>
	; Masm32 print to avoid slot changes, pulls in CoGetMalloc
	aPrint str$(eax), 9, " bytes for &algo&", 13, 10
  else
	Print Str$("%i\tbytes for &algo&\n", eax)
  endif
  popad
ENDM

MbHeap16 PROTO
A16Max=100
Alloc16 MACRO cBytes, flags:=<HEAP_ZERO_MEMORY>
  push flags
  push cBytes
  call MbHeap16
ENDM

Free16 MACRO pMem
  push -127
  push pMem
  call MbHeap16
ENDM

sgPl=0
sglimit=0
sgInit=0
gvPos=0
sgDefStart=0
sgct=0
InitLine=0
SetGlobals MACRO args:VARARG
LOCAL ct, arg, is, is2, argType, tmp$, tmpLine$, argNew, sgSize, isCode, dw$
  isCode INSTR @CurSeg, <TEXT>
  ifb <args>
	is=@Line-InitLine
	if (is gt 0) and (is le 9) and sgInit
		echo ## Init does SetGlobals - not needed here ##
	endif
	sgInit=1
	if sgPl
		ife sgct
			tmp$ CATSTR <## line >, %@Line, <: using ebx not allowed in plugins, except for initialising globals ##>
			% echo tmp$
			.err 
		endif
	else
		mov ebx, offset gvStart+128	; in multithreaded apps, alloc gvPos bytes, copy, set ebx
	endif
	WHILE sgct
		tmpLine$ CATSTR <Sgi>, %sgct, <$>
		is=1
		WHILE is
			is INSTR tmpLine$, <#>
			if is
				tmp$ SUBSTR tmpLine$, 1, is-1
				tmp$
				tmpLine$ SUBSTR tmpLine$, is+1
			endif
		ENDM
		sgct=sgct-1
	ENDM
  else
	if isCode		; SG top: if a RECT global is present, then top would be illegal because it's a member of RECT
		.DATA?
	endif
	dw$ equ <dword>
	for arg, <args>
		LOCAL sg$, gv$, argSet$, isb
		if gvPos ge 256
			ife sglimit
				echo ## SetGlobals warning: +128 exceeded after arg ##
			endif
			sglimit=sglimit+1
		endif
		is2 INSTR <arg>, <=>	; MyR4:REAL4=123.456
		ife is2
			argSet$ equ <>
			gv$ equ <arg>
		else
			argSet$ SUBSTR <arg>, is2+1
			gv$ SUBSTR <arg>, 1, is2-1
		endif
		argType equ <dword>
		is INSTR gv$, <$>
		ife is
			argType equ <dw$>
			is INSTR <arg>, <:>
			ife is
				is INSTR <arg>, < >
			endif
			if is
				gv$ SUBSTR <arg>, 1, is-1
					ifidn gv$, <int>
						gv$ equ <DWORD>
					endif
					ifidn gv$, <float>
						gv$ equ <REAL4>
					endif
					ifidn gv$, <double>
						gv$ equ <REAL8>
					endif
					if (opattr gv$) ne atImmediate
						if is2
						  argType SUBSTR <arg>, is+1, is2-is-1
						else
						  argType SUBSTR <arg>, is+1
						endif
					else
						dw$ SUBSTR <arg>, 1, is-1
						argType SUBSTR <arg>, 1, is-1
						if is2
						  gv$ SUBSTR <arg>, is+1, is2-is-1
						else
						  gv$ SUBSTR <arg>, is+1
						endif
					endif
				endif
			ifidni argType, <int>
			  argType equ <DWORD>
			endif
			ifidni argType, <float>
			  argType equ <REAL4>
			endif
			ifidni argType, <double>
			  argType equ <REAL8>
			endif
		endif
		ct=1
		is INSTR <arg>, <[>
		if is
			is2 INSTR <arg>, <]>
			gv$ SUBSTR <arg>, 1, is-1
			tmp$ SUBSTR <arg>, is+1, is2-is-1
			ct=tmp$
		endif
		is=1
		ifidni argType, <dword>
			elseifidni argType, <sdword>
			elseifidni argType, <word>
			elseifidni argType, <sword>
			elseifidni argType, <byte>
			elseifidni argType, <sbyte>
			elseifidni argType, <qword>
			elseifidni argType, <oword>
			elseifidni argType, <real4>
			elseifidni argType, <real8>
			elseifidni argType, <real10>
		else
			is=0
			argNew CATSTR gv$, < equ [ebx.>, argType, <+>, %gvPos, <-128]>
		endif
		if is
			argNew CATSTR gv$, < equ >, argType, < PTR [ebx+>, %gvPos, <-128]>
		endif
		argNew
		ifnb argSet$
			sgct=sgct+1
			is2 INSTR <arg>, <$>
			if is2
				.DATA
				sg$ db argSet$, 0
				.DATA?
				@CatStr(<Sgi>, %sgct, <$ equ >, <<mov gv$, offset sg$# >>)
			elseifidni argType, <dword>
				@CatStr(<Sgi>, %sgct, <$ equ >,  <<push argSet$#pop gv$# >>)
			elseifidni argType, <word>
				@CatStr(<Sgi>, %sgct, <$ equ >,  <<pushw argSet$#pop gv$# >>)
			elseifidni argType, <byte>
				@CatStr(<Sgi>, %sgct, <$ equ >,  <<push argSet$#pop eax#mov gv$, al# >>)
			elseifidni argType, <real4>
				.DATA
				sg$ REAL4 argSet$
				.DATA?
				@CatStr(<Sgi>, %sgct, <$ equ >,  <<fld sg$#fstp gv$# >>)
			elseifidni argType, <real8>
				.DATA
				sg$ REAL8 argSet$
				.DATA?
				@CatStr(<Sgi>, %sgct, <$ equ >,  <<fld sg$#fstp gv$# >>)
			elseifidni argType, <real10>
				.DATA
				sg$ REAL10 argSet$
				.DATA?
				@CatStr(<Sgi>, %sgct, <$ equ >,  <<fld sg$#fstp gv$# >>)
			elseifidni argType, <qword>
				.DATA
				sg$ QWORD argSet$
				.DATA?
				@CatStr(<Sgi>, %sgct, <$ equ >,  <<fild sg$#fistp gv$# >>)
			else
				tmp$ CATSTR <## line >, %@Line, <: >, <arg>, < is not possible ##>
				% echo tmp$
				.err
			endif
		endif
		gvPos=gvPos+argType*ct
		if gvPos ge 4096
			tmp$ CATSTR <## line >, %@Line, <: SetGlobals i>, <s for frequently used variables, max 4096 bytes - >, %gvPos, < i>, <s too much ##>
			% echo tmp$
			.err
		endif
	ENDM
	if isCode
		.CODE
	endif
  endif
ENDM
ChooseString=65536
ChooseReal=-126
ChooseError=-127
Choose MACRO inx, args:VARARG
Local ct, c1$, is
  push ecx
  PushPlusMinus inx
  pop ecx
  ct=0
  m2m edx, -127	; error code
  for arg, <args>
	LOCAL numx
	c1$ SUBSTR <arg>, 1, 1
	.if ecx==ct
		ifidn c1$, <">
			mov edx, repargA(arg)
		elseifidn c1$, <'>
			mov edx, repargA(arg)
		elseif @InStr(1, <arg>, <.>)
			inc edx	; -126
			.DATA
			if @SizeStr(<arg>) gt 6
				numx REAL10 arg
			else
				numx REAL4 arg
			endif
			.CODE
			fld numx
		else
			mov edx, arg
		endif
	.endif
	ct=ct+1
  endm
  pop ecx
  xchg eax, edx
  exitm <sdword ptr eax>
ENDM
GpaCt=-4
Declare MACRO NewMac1:REQ, dwords1:VARARG
LOCAL GPA$, nustr, is, is2, isv, isF, isD, isVar, isVarSize, isVar$, dwords, tmp$, ThisGpaCt
  tmp$ equ <NewMac1>
  isVar INSTR tmp$, <As>
  isv INSTR tmp$, <void>
  isD INSTR tmp$, <double>
  isF INSTR tmp$, <float>
  is INSTR tmp$, <,>
  if is
	dwords SUBSTR tmp$, is+1
	NewMac SUBSTR tmp$, 1, is-1
  else
	dwords equ <dwords1>
	NewMac equ <NewMac1>
	if isv
		NewMac SUBSTR NewMac, isv+5
	elseif isF
		NewMac SUBSTR NewMac, isF+6
	elseif isD
		NewMac SUBSTR NewMac, isD+7
	endif
  endif
  if MbUseErrLine
	mov MbErrLine, @Line
	tmp$ CATSTR NewMac, <(0)>
	is=0
	% FORC c$, tmp$
	 ifidn <c$>, <(>
	 	is=2
	 endif
	ENDM
	ife is
		ife isVar
			% echo ## NewMac ALREADY DEFINED - Masm32 macro? ##
		endif
	endif
  endif
  is INSTR NewMac, <=>	; 123=GetWhateverByOrdinal
  if is
	is2 INSTR NewMac, <#>	; VB syntax: Declare #123=Whatever, 2 -> mov ecx, Whatever(1, 2)
	tmp$ SUBSTR NewMac, is2+1, is-is2-1
	GPA$ CATSTR <invoke GetProcAddress, >, <DllTable[>, %MbDllCt, <]>, <, >, tmp$
	NewMac SUBSTR NewMac, is+1
  else
	if isVar
		isVarSize SUBSTR NewMac, isVar+3
		isVar$ CATSTR isVarSize, < ptr [eax]>
		NewMac SUBSTR NewMac, 1, isVar-2
		dwords equ <?>
	endif
	.DATA
	is2 INSTR dwords, <Alias>
	if is2
		tmp$ SUBSTR dwords, is2+6
		dwords SUBSTR dwords, 1, is2-1
		tmp$ CATSTR <nustr db >, tmp$, <, 0>
	else
		tmp$ CATSTR <nustr db ">, NewMac, <", 0>
	endif
	tmp$
	.CODE
	GPA$ CATSTR <invoke GetProcAddress, >, <DllTable[>, %MbDllCt, <]>, <, offset nustr>
  endif
  push ecx
  GPA$
  pop ecx
  GpaCt=GpaCt+4
  if DecRTE
	ExternDef MbError0:NEAR
  	test eax, eax
  	je MbError0
  endif
  mov DllTable[40+GpaCt], eax
  ThisGpaCt=GpaCt
  isCcall INSTR dwords, <C:>
  ; % echo creating [NewMac]
	NewMac macro TheArgs:VARARG
	LOCAL ctA, ctR, ctP, rev$, pushrev, is, is2, tmp$, tmp2$, isCcall, newargs, argEsp, numArgs, immReal, tCount, oa
	  ctA=0		; args
	  ctR=0		; rev$ elements
	  ctP=0		; additional pushs
	  argEsp=0
	  rev$ equ <>
	  isCcall INSTR dwords, <C:>
	  if isCcall
		newargs SUBSTR dwords, isCcall+2
	  else
		newargs equ dwords
	  endif
	  ifidn <TheArgs>, <#>
		if isCcall
			tmp$ CATSTR <## NewMac i>, <s CCall: you MUST put 'add esp, 4*>, %isCcall, <' after line >, %@Line, < ##>
			% echo tmp$
		endif
		EXITM <DllTable[40+ThisGpaCt]>
	  endif
	  FOR arg, <TheArgs>
		tCount=0
	  	ctA=ctA+1
		; tmp$ CATSTR <TheArg #>, %ctA, < = >, <arg>, < with tc=>, %tCount
		; % echo tmp$
		is INSTR <arg>, <">
		if is
			is INSTR <arg>, <\n>
			ife is
				is INSTR <arg>, <\t>
			endif
			if is
				tmp2$ equ repargA(cStyle$(<arg>))
			else
				tmp2$ equ repargA(<arg>)	; JWasm likes it complicated
			endif
		  	rev$ CATSTR <push >, tmp2$, <#>, rev$
		else
			is INSTR <arg>, <addr>
			if is eq 1
			  	ctR=ctR+1
			  	rev$ CATSTR <push edx#>, rev$
			  	rev$ CATSTR <lea edx,>, @SubStr(<arg>, 5), <#>, rev$
			else
				is INSTR <arg>, <.>
				ife is
			  		tCount=TYPE(arg)
			  	endif
				is INSTR <arg>, <::>	; qWord as 0::12345678h or edx::eax?
				if is
			  		ctR=ctR+1
				  	rev$ CATSTR <d@>, @SubStr(<arg>, is+2), <#>, rev$
				  	rev$ CATSTR <d@>, @SubStr(<arg>, 1, is-1), <#>, rev$
				else
					ifidni <arg>, <esp>
						argEsp=ctA+ctR
					endif
					if tCount
					  	rev$ CATSTR <d@>, <arg#>, rev$
					else
						is INSTR <arg>, <[ebx.> 	; this section to satisfy JWasm, and ML in case of immediate args...
						if is
							is2 INSTR arg, <+>
							tmp$ SUBSTR arg, is+5, 3
							tCount=tmp$
						endif
						is INSTR <arg>, <.>
						if is and (opattr arg) eq 0
							.DATA
						  	rev$ CATSTR <d@>, <immReal#>, rev$
							if isD
								immReal REAL8 arg
							  	rev$ CATSTR <d@>, <immReal[4]#>, rev$
						  		ctR=ctR+1
						  		ctP=ctP+1
							else
								immReal REAL4 arg
							endif
							.CODE
						else
						  	rev$ CATSTR <d@>, <arg#>, rev$
						endif
					endif
				  	is=0
				  	WHILE tCount gt 4
				  		is=is+4
				  		tCount=tCount-4
				  		ctR=ctR+1
				  		ctP=ctP+1
					  	rev$ CATSTR <d@>, <arg[>, %is, <]#>, rev$
				  	ENDM
				endif
			endif
		endif
	  ENDM
	  if (opattr newargs) eq atImmediate
		if ctA ne newargs
	  		tmp$ CATSTR <## NewMac: >, %ctA, < args received, >, %newargs, < expected ##>
			% echo tmp$
			.err
		endif
	  endif
	  if isCcall
	  	isCcall = ctA+ctP			; for stack correction
	  endif
	  push ecx
	  numArgs=ctA
	  ctA=ctA+ctR
	  WHILE ctA
		is INSTR rev$, <#>
		pushrev SUBSTR rev$, 1, is-1
		isp4 INSTR pushrev, <d@>
		if isp4 eq 1
			pushrev SUBSTR pushrev, 3
			pushrev CATSTR <push dword ptr >, pushrev
		endif 
		if argEsp eq ctA
			lea edx, [esp+4*(numArgs-ctA+1)]
			push edx
		if usedeb
			% echo @CatStr(<** >, %@Line, <: using current esp as buffer start **>)
		endif
		else
			pushrev
		endif
		ctA=ctA-1
		if ctA
			rev$ SUBSTR rev$, is+1
		endif
	  ENDM
	  if isVar
	  	mov eax, DllTable[40+ThisGpaCt]
	  	ifnb <TheArgs>
		  	oa = opattr TheArgs
	  		if oa eq atImmediate
				add eax, isVarSize*TheArgs
	  		else
				lea eax, [eax+isVarSize*TheArgs]
	  		endif
		endif
		EXITM isVar$
	  else
		  call DllTable[40+ThisGpaCt]
		  if isCcall
			add esp, 4*isCcall
		  endif
	  endif
	  pop ecx
	  if isv
	  	EXITM <>
	  elseif isF or isD
		EXITM <ST(0)>
	  else
		EXITM <eax>
	endif
	ENDM
ENDM
MbArrMM=	0
MbArrXY=	0
ArrayMean MACRO args:VARARG
  if stLastType eq MbDword or stLastType eq MbReal4 or stLastType eq MbReal8
	MbArrMM=	1+MbArrXY+1024
	MbArrXY=	0
	ffree st(7)
	fldz
	ArraySort args
  else
	.err @CatStr(<## line >, %@Line, <: valid array types are DWORD, REAL4 and REAL8>)
  endif
ENDM
ArrayMinMax MACRO args:VARARG
  if stLastType eq MbDword or stLastType eq MbReal4 or stLastType eq MbReal8
	MbArrMM=	1+MbArrXY
	MbArrXY=	0
	ArraySort args
  else
	.err @CatStr(<## line >, %@Line, <: valid array types are DWORD, REAL4 and REAL8>)
  endif
ENDM
ArraySort MACRO IdOrPtr, pKey:=<0>, fillmode	; uses radix sort
LOCAL oa, isID, is, is1, is2, pArr, elct, tmp$, ptrKey, oaKey, curType, smode
  smode=MbArrMM or 64	; default: ascending (+)
  MbArrMM=0
  ifidni <fillmode>, <fill> 	; ArraySort MyR4(+), KeyArr(), fill
	smode=smode or 2
  endif
  is INSTR <pKey>, <-0> 	; KeyArr() passed, negative ID of numeric array
  if is eq 1
	oaKey = atMemory
	ptrKey equ [NumArrTable&pKey&*4]	; ArraySort MyR4(+), KeyArr()
  else
	oaKey = (opattr pKey) AND 127	; ArraySort MyR4(-), esi after lea esi, KeyArr(0)
	ptrKey equ <pKey>
  endif
  isID INSTR <IdOrPtr>, <-0>	; negative ID = numeric array
  is INSTR <IdOrPtr>, <:>
  oa = 0
  if is
	pArr SUBSTR <IdOrPtr>, 1, is-1
	elct SUBSTR <IdOrPtr>, is+1	;; value after :
	is INSTR elct, <->	; e.g. +eax
	if is
		elct SUBSTR elct, 2
		smode=smode and 31	; 0 = descending (-)
	endif
  elseif isID
	pArr equ <IdOrPtr>
	elct equ <@@>	;; yet unknown
  else
	tmp$ CATSTR <## ArraySort, line >, %@Line, <: use >, <IdOrPtr>, <:count ##>
	% echo tmp$
	.err
	exitm
  endif
  ife isID
	is1 INSTR pArr, <REAL>
	is2 INSTR pArr, <PTR>
	if is2
		tmp$ SUBSTR pArr, 1, 5	; 5=REAL PTR or QWORD PTR
		smode=smode or tmp$
		if is1
			smode=smode or 32	; Real
		endif
	else
		smode=smode or DWORD	; no size specified, assume DWORD
	endif
	push smode	; size+fgMinMax1+fgFill2+fgReal32+fgDirection64
	push ptrKey
	push elct
	if is2
		tmp$ SUBSTR pArr, is2+4
		push tmp$
	else
		push pArr
	endif
  else					; MasmBasic array
	curType CATSTR <stArrType>, %(-pArr)	; RunMacro
	smode=smode or curType
	if (curType eq REAL4) or (curType eq REAL8)
		smode=smode or 32
	endif
	push smode
	push ptrKey	; maxsd
	ifidn elct, <edx>	; (+) or (-)=ID:edx
		push edx	; elements
		push eax	; ptr to element 0
	else
		ifidn elct, <@@>
			mov edx, [NumArrTable+4*pArr]
			push [edx-8]	; #elements
		else
			is INSTR elct, <+>
			if is
				elct SUBSTR elct, is+1
			endif
				push elct
		endif
		push [NumArrTable+4*pArr]
	endif
  endif
  call MbArrSort	; invoke MbArrSort, esi, ebx, 0, size+fgMinMax1+fgFill2+fgReal32+fgDirection64
ENDM

ArraySearch MACRO pArray, rangeBytes, xPattern, sizeBWD:=<DWORD>
LOCAL is, oa ;, pattern
  is INSTR <xPattern>, <">
  ife is
	is INSTR <xPattern>, <'>
  endif
  if is
	pattern equ Mirror$(<xPattern>)
  else
	pattern equ <xPattern>
  endif
  push sizeBWD-WORD		; 4, 2, 1 -> 2=dword, 0=word, -1=byte
  oa = (opattr pattern) AND 127
  if sizeBWD eq DWORD
	push pattern
  elseif sizeBWD eq WORD
	if oa eq atImmediate
		push pattern*00010001h
	else
		ifdifi pattern, <eax>
			mov eax, pattern
		endif
		imul eax, eax, 00010001h
		push eax
	endif
  else
	if oa eq atImmediate
		push pattern*01010101h
	else
		ifdifi pattern, <eax>
			mov eax, pattern
		endif
		imul eax, eax, 01010101h
		push eax
	endif
  endif
  ArrSearchP PROTO
  push rangeBytes
  push pArray
  call ArrSearchP		; invoke ArrSearchP, pSrc, len, pSearch, Mode
  EXITM <eax>
ENDM

GetField MACRO SrcDotField		; trashes and returns eax; see ragdog
LOCAL is, is2, src, field
  is INSTR <SrcDotField>, <.>
  if is
	is2 INSTR is+1, <SrcDotField>, <.>
	if is2 gt is
		is = is2
	endif
  else
	.err <## syntax: GetField(rec.field) ##>
  endif
  src SUBSTR <SrcDotField>, 1, is-1
  field SUBSTR <SrcDotField>, is+1
  ifdifi src, <eax>   
	mov eax, src
  endif
  and eax, mask field
  if field
	shr eax, field
  endif
  EXITM <eax>
ENDM

SetField MACRO SrcDotField, TheVal, forceAnd		; trashes and returns eax; checks immediate values for overflow
LOCAL is, is2, src, field, maxv, HasVal
  HasVal = 999					;; default: mov eax, TheVal
  is INSTR <SrcDotField>, <.>
  if is
	is2 INSTR is+1, <SrcDotField>, <.>
	if is2 gt is
		is = is2
	endif
  else
	.err <## syntax: SetField rec.field, 123 ##>
  endif
  src SUBSTR <SrcDotField>, 1, is-1
  field SUBSTR <SrcDotField>, is+1
  if ((opattr(TheVal)) AND 127) eq 36
	HasVal = TheVal
	maxv = (2 SHL (WIDTH field - 1))-1		;; or gt with maxv = mask field SHR field
	if (TheVal gt maxv) or (TheVal lt -1)
		tmp$ CATSTR <## line >, %@Line, <: overflow for SetField >, <SrcDotField>, <, >, <TheVal>, <, max=>, %maxv, < **>
		.err tmp$
	endif
  endif
  if HasVal
	ifdifi <TheVal>, <eax>
		if (HasVal ge -128) and (HasVal le 127)	;; 3 bytes
			if TheVal eq -1
				push maxv
			else
				push TheVal
			endif
			pop eax
		else
			mov eax, TheVal		;; 5 bytes
		endif
	endif
	if field
		shl eax, field
	endif
  else
	sub eax, eax
  endif
  ifnb <forceAnd>
	and src, not mask field
  endif
  or src, eax
ENDM

; GNU Scientific Library ##
; #### 10 October 2015: if usedeb then download and install GSL if not present ####
; gsl_OldVersion=1	; uncomment to get and use shorter 2006 version
gsl_block STRUCT
  gbSize	dd ?
  gbData	REAL8 ?
gsl_block ENDS
gsl_cheb_series STRUCT
  gcC	dd ?	; ptr to REAL8
  gcOrder	dd ?
  gcA	REAL8 ?
  gcB	REAL8 ?
  gcOrder_sp dd ?
  gcF	REAL8 ?
gsl_cheb_series ENDS
gsl_combination STRUCT
  gcN	dd ?
  gcK	dd ?
  gcData	dd ?	; ptr to REAL8
gsl_combination ENDS
gsl_complex STRUCT
  gsl_co	REAL8 ?, ?
gsl_complex ENDS
gsl_matrix STRUCT
  gmSize1	dd ?
  gmSize2	dd ?
  gmTda	dd ?
  gmData	dd ?	; ptr to REAL8
  gmBlock	dd ?	; ptr to gsl_block
  gmOwner	dd ?
gsl_matrix ENDS
gsl_multiset STRUCT
  gcN	dd ?
  gcK	dd ?
  gcData	dd ?	; ptr to REAL8
gsl_multiset ENDS
gsl_ntuple STRUCT
  gnFile	dd ?	; ptr to FILE
  gnNtuple_data dd ?	; ptr to void
  gnSize	dd ?
gsl_ntuple ENDS
gsl_permutation STRUCT
  gpSize	dd ?
  gpData	dd ?	; ptr to REAL8
gsl_permutation ENDS
gsl_sf_result_struct STRUCT
gsVal	REAL8 ?
gsErr	REAL8 ?
gsl_sf_result_struct ENDS
gsl_vector STRUCT
gvSize	dd ?
gvStride	dd ?
gvData	REAL8 ?
gvBlock	gsl_block <?>
gvOwner	dd ?
gsl_vector ENDS

; the macros ****
gslCt=0
gslInit=0
gsl_INIT MACRO
LOCAL is, gslHandle$, gslName$, @retry
  if gslInit
	echo gsl_INIT done by Init
	exitm
  endif
  ifndef gslLibName
	ifndef gsl_OldVersion
		gslLibName equ "libgsl-0.dll"
		gslZipSrc equ Chr$("https://oscats.googlecode.com/files/gsl-1.15-dev-win32.zip")
	else
		gslLibName equ "libgsl.dll"
		gslZipSrc equ Chr$("http://netassist.dl.sourceforge.net/project/gnuwin32/gsl/1.8/gsl-1.8-bin.zip")
	endif
	gslDllPath equ "\masm32\MasmBasic\GnuScLib\DLL\bin"
  endif	
.DATA?
hGslDll	dd ?
GslHandles	dd gslCt dup(?)
.CODE
	push ecx
	push ebx
	push esi
	push edi
	mov edi, MAX_PATH
	sub esp, edi
	invoke GetCurrentDirectory, edi, esp
@retry:	invoke SetCurrentDirectory, Chr$(gslDllPath)
	mov esi, Chr$(gslLibName)
	if usedeb
	.if !Exist(esi)
		MsgBox 0, Cat$(gslDllPath+"\"+gslLibName+" not found."+CrLf$+"Try to install it from the web?"), "gsl_INIT error:", MB_OKCANCEL
		.if eax==IDOK
			mov ebx, gslZipSrc
			UnzipInit ebx
			.if Sign?
				Print eax	; print an error message
			.else
				push eax	; UnzipInit returns a comment or an empty string
				push edx	; #files returned in edx
				xor ecx, ecx
				.Repeat
						mov esi, Files$(ecx)
						if 0
						   PrintLine Str$(GfSize(ecx)), Tb$, GfDate$(ecx), Spc2$, GfTime$(ecx), Tb$, esi
						endif
						.if Instr_(esi, ".dll", 1)
							.if !Instr_(esi, ".dll.a", 1)
								UnzipFile(ecx, Cat$(Left$(MbExeFolder$, 2)+Left$(gslDllPath, Rinstr(gslDllPath, "\bin", 1))))
							.endif
						.endif
						inc ecx
				.Until ecx>=stack
				pop edx
				pop eax
				PrintLine "GSL installed with zip comment [", eax, "] from ", ebx, CrLf$, CrLf$
				UnzipExit
				jmp @retry
			.endif
		.endif
	.endif
	endif
	mov ebx, rv(LoadLibrary, esi)
	ClearLastError
	invoke SetCurrentDirectory, esp	; restore current folder
	add esp, edi
	test ebx, ebx
	jne gslOK
gslErr:	Exit 77
	MbExit=0
gslOK:	mov edi, offset hGslDll	; first stosd is hGslDll
	stosd
	mov esi, offset gslNameTable
	push gslCt-1
	.Repeat
		invoke GetProcAddress, ebx, esi
		test eax, eax
		je gslErr
		stosd	; write a handle to GslHandles
		.Repeat
		    lodsb
		.Until !al
		dec stack
	.Until Sign?
	pop ecx
	pop edi
	pop esi
	pop ebx
	pop ecx
ENDM
gsl_EXIT MACRO
  if gslInit
	gslInit=0
	push ecx
	invoke FreeLibrary, hGslDll
	pop ecx
  endif
ENDM

MbGslV=0
gslvar MACRO args:VARARG
   MbGslV=1
   gsl args
ENDM
gsl MACRO argsL, argsR:VARARG
LOCAL tmpArg$, ftype, MacName$, fargs$, arg1$, c1$, isL, isR, isB, args, gslArgsLocal$, isVar, numArgs, curMac, isCode
  isCode INSTR @CurSeg, <TEXT>
  if isCode
	ife gslCt
		echo ## you need gsl_INIT ##
	endif
	.DATA
  endif
  isVar=MbGslV
  MbGslV=0		; clear VAR flag
  ifb <argsR>
	args equ <argsL>
  else
	args CATSTR <argsL>, <, >, <argsR>
  endif
  isL INSTR args, <(>
  isR INSTR args, <)>
  fargs$ SUBSTR args, isL+1, isR-isL-1
;   % echo ___ARGS=[args]___fargs=[fargs$]___
  fargs$ CATSTR fargs$, <, >
  WHILE 1
	tx$ SUBSTR args, isL-1, 1
	ifdif tx$, < >
		EXITM
	endif
	isL=isL-1
  ENDM
  isB INSTR args, < >	; first blank
  MacName$ SUBSTR args, isB+1, isL-isB-1	; gsl_name
  ftype SUBSTR args, 1, isB-1	; void, int, double ... gsl_name
  isL INSTR MacName$, <*>
  isR INSTR MacName$, <gsl_>
  if (isL gt 0) and (isR gt isL)
	MacName$ SUBSTR MacName$, isR
	ftype equ <DWORD>	; ptr to gsl_whatever structure
  endif
  curMac=gslCt
  gslCt=gslCt+1
  isR INSTR fargs$, <,>
  if isR eq 1
	isR=0
  endif
  gslArgsLocal$ equ <>
  numArgs=0
  While isR
	numArgs=numArgs+1
  	WHILE 1
  		c1$ SUBSTR fargs$, 1, 1
  		ifdif c1$, < >
  			EXITM	; skip leading spaces
  		endif
  		fargs$ SUBSTR fargs$, 2
  		isR=isR-1
  	ENDM
	arg1$ SUBSTR fargs$, 1, isR-1
	tmpArg$ SUBSTR fargs$, 1, 4
	ifidni tmpArg$, <cons>
		tmpArg$ SUBSTR fargs$, 7, 4	; ignore the const double etc
	endif
	isB INSTR fargs$, <gsl_complex>
	if isB
		.err complex not implemented
	endif
	isB INSTR fargs$, <unsigned>
	if isB
		tmpArg$ SUBSTR fargs$, isB+9, 4
	endif		
	isB INSTR arg1$, <[>	;; e.g. const double data[]
	if isB
		gslArgsLocal$ CATSTR gslArgsLocal$, <, :DWORD>
	else
			isB INSTR < doub# sing# floa# int # gsl_# size# FILE# unsi#>, tmpArg$	; frequent gsl sizes
			ife isB
				tmp$ CATSTR <## Invalid size ">, arg1$, <" in line >, %@Line, < ##>
				% echo tmp$
				.err
			elseif isB le 2
				gslArgsLocal$ CATSTR gslArgsLocal$, <, :REAL8>
			elseif isB le 14
				gslArgsLocal$ CATSTR gslArgsLocal$, <, :REAL4>
			else
				gslArgsLocal$ CATSTR gslArgsLocal$, <, :DWORD>
			endif
	endif
	fargs$ SUBSTR fargs$, isR+1
	isR INSTR fargs$, <,>
  ENDM
  tmp$ CATSTR <db ">, MacName$, <", 0>
  ifndef gslNameTable
	tmp$ CATSTR <gslNameTable >, tmp$
  endif
  tmp$
  if isCode
	.CODE
  endif
  ifnb gslArgsLocal$
	gslArgsLocal$ SUBSTR gslArgsLocal$, 4
  endif
	MacName$ macro args:VARARG		; gsl_xx
	LOCAL is, espCt, ctArgs, reva$, tmptype, gslType, MacHandle, arg, argx
		ThisMac equ <GslHandles[curMac*DWORD]>
		ifb <args>
			if isVar
				ifidni ftype, <double>
				  .err <not implemented>
				else
				  mov eax, ThisMac	; no push ecx
				  EXITM <[eax]>	; GPA retrieves the address of an exported function or variable
				endif
			else
				push edx
				push ecx
				call ThisMac
				pop ecx
				pop edx
			endif
		else
			push edx
			push ecx
			is INSTR <args>, <ST>
			ife is
					tmptype typedef PROTO C :gslArgsLocal$	; let invoke do the job
					gslType typedef PTR tmptype
					reva$ equ <>
					for argx, <args>
						is INSTR <argx>, <&>
						if is eq 1
							reva$ CATSTR reva$, <, addr >, @SubStr(<argx>, 2)
						else
							reva$ CATSTR reva$, <, >, <argx>
						endif
					endm
					invoke gslType PTR ThisMac reva$
			else
				espCt=0	; stack correction by hand
				ctArgs=numArgs
				reva$ equ <#_>
					FOR arg, <args>
						reva$ CATSTR <#>, <arg>, reva$
					ENDM
					reva$ SUBSTR reva$, 2
					WHILE 1
						is INSTR reva$, <#>
						ife is
							EXITM
						endif
						arg SUBSTR reva$, 1, is-1
						reva$  SUBSTR reva$, is+1
						is INSTR arg, <ST>
						if is eq 1
							espCt=espCt+2*DWORD
							push eax		; R8 slot
							push edx
							ifidn arg, <ST>
								fstp REAL8 PTR [esp]	; store + pop
							elseifidni arg, <STnp>
								fst REAL8 PTR [esp]  	; no pop
							else
								.err @CatStr(<## line >, %@Line, <: valid are ST and STnp only ##>)
							endif
						else
							push arg
							espCt=espCt+DWORD
						endif
						ctArgs=ctArgs-1
					ENDM
					if ctArgs
						.err <wrong # of args>
					else
						call GslHandles[curMac*DWORD]
						add esp, espCt
					endif
			endif
			pop ecx
			pop edx
		endif
		ifidni ftype, <double>
			Exitm <ST(0)>
		elseifidni ftype, <void>
			Exitm <>
		else
			Exitm <eax>
		endif
	ENDM
ENDM			; ### end GSL ###
ifndef gcMargin
	gcMargin=2
endif
gcOldMargin=-999
PropertyTagFrameDelay	= 5100h
PropertyTagLoopCount	= 5101h
PropertyTagGlobalPalette	= 5102h
PropertyTagIndexBackground=5103h
PropertyTagIndexTransparent=5104h
PropertyTagSoftwareUsed	= 0131h
PropertyTagArtist		= 013Bh
PropertyTagExifUserComment = 9286h
PropertyTagCopyright	= 8298h		; Null-terminated character string that contains copyright information
GdipPropertyItem STRUCT DWORD
itemID	dd ?
itemLen	dd ?
itemType	dw ?
itemPtrValues	dd ?
GdipPropertyItem ENDS
giMaxImg=100	; see mb4lib
MbGDIP struc
GdiplusVersion			dd ?	; GdiplusStartupInputEx
DebugEventProc			dd ?
SuppressBackgroundThread		BOOL ?
SuppressExternalCodecs		BOOL ?
jjMemStream		dd ?
jjStream		dd ?
jjToken		dd ?
jjGraphicsObj		dd ?
jjCallback		dd ?
jjWidth		dw ?
jjHeight		dw ?
jjImgObject		dd ?
jjSpeed		dd ?
jjLastError		dd ?
jjGdiDC		dd ?
jjBmpFromFile		dd ?		; for getbmpfromfilew
jjBitmap		BITMAP <>
jjFileRead$		dd ?
giMargin		dd ?
giX		dd ?
giY		dd ?
giW		dd ?
giH		dd ?
jjRes1		dd ?
jjThisFrame		dd ?
jjTicksOnPaint		dd ?
jjImgID		dd ?
jjFrameTicks		dd 2*giMaxImg dup(?)		; current frame, ticks - use with jjImgID
jjPath		dw MAX_PATH dup(?)
MbGDIP ends
ExternDef GdiSI:MbGDIP	; for testing, use mb.asc data
gsi equ [esi.MbGDIP]
giGraphics	equ gsi.jjGraphicsObj
giImage	equ gsi.jjImgObject
giImageID	equ gsi.jjImgID
giSpeed	equ gsi.jjSpeed
gicbObj	equ <gicbObj_is_obsolete_use_giImage_instead>
GuiImageSpeed MACRO speed:=<100>
  ffree st(7)
  push 32
  if opattr(speed) eq atImmediate
	if speed gt 16000
		push 15999
	else
		push speed
	endif
  else
	push speed
  endif
  fldlg2
  fiadd stack
  fidivr word ptr [esp+3]	; 8000
  pop edx
  fistp stack
  pop GdiSI.jjSpeed	; giSpeed
ENDM
sitfWarning=0
SaveImageToFile MACRO siFileW, quality:=<0>
  push ebx
  push ecx
  push eax		; hBmp slot
  mov ebx, wRec$(repargA(siFileW))
  ife sitfWarning
	sitfWarning=1
	% echo @CatStr(<** line >, %@Line, <: do NOT save animated images with their original name - only the first frame gets saved!! **>)
  endif
  if usedeb
	.if GdiSI.jjCallback==0
		deb 1, "SaveImageToFile is for use with GuiImageCallback only", $$ebx
	.endif
  endif
  mov ecx, esp
  gdi+ GdipCloneImage, giImage, ecx
  GetEncoderCLSID PROTO :DWORD
  invoke GetEncoderCLSID, ebx
  mov ecx, stack
  gdi+ GdipSaveImageToFile, ecx, ebx, eax, quality
  pop ecx
  gdi+ GdipDisposeImage, ecx
  pop ecx
  pop ebx
ENDM
GuiImageCallback MACRO gicb	; disabling will not work in this file because the GdiSI struct is local for imgpaint
  mov GdiSI.jjCallback, gicb
ENDM
GuiImage MACRO f0$:=<CL$()>, x, y, w, h
Local oa, c1$, tmp$, isDC, isDCUrl, filename, giDC, isDCP, isDCN
  usedIpp=1
  InfoWH=-127
  isDC INSTR <f0$>, <#>
  isUrl=0
  if isDC
	giDC SUBSTR <f0$>, 1, isDC-1
	filename SUBSTR <f0$>, isDC+1
  else
	giDC equ PtDC
	filename equ <f0$>
	isUrl INSTR <f0$>, <://>
  endif
  c1$ SUBSTR filename, 1, 1
  isP INSTR <f0$>, <+>
  isN INSTR <f0$>, <->
  if isP or isN
	oa=0
  elseifidn c1$, <">
	oa=0
  elseifidn c1$, <'>
	oa=0
  else
	oa=opattr filename
  endif
  if oa eq atImmediate
	if (filename lt 48) or (filename gt 127)
		tmp$ CATSTR <## GuiImage, line >, %@Line, <: allowed range for image resource IDs is 48...127 ##>
		% echo tmp$
		.err
	endif
	push filename	; 48...127
  else
	if (isUrl ge 4) and (isUrl le 7)
		void FileRead$(filename)
		ExternDef txFrl:BYTE
		push offset txFrl
	elseif isP
		tmp$ SUBSTR <f0$>, isDC+1, isP-isDC-1
		push tmp$
		tmp$ SUBSTR <f0$>, isP+1
		add stack, tmp$
	elseif isN
		tmp$ SUBSTR <f0$>, isDC+1, isN-isDC-1
		push tmp$
		tmp$ SUBSTR <f0$>, isN+1
		sub stack, tmp$
	else
		push repargA(filename)
	endif
  endif
  if gcMargin ne gcOldMargin
	m2m GdiSI.giMargin, gcMargin
	gcOldMargin=gcMargin
  endif
  ifidni <x>, <fit>
	push -100	; fit canvas
  elseifidni <x>, <info>
	push InfoWH	; get w+h, don't draw
  elseifb <x>
	push -99	; original size
  else
	m2m GdiSI.giX, x
	m2m GdiSI.giY, y
	ifb <w>
		and GdiSI.giW, 0
		and GdiSI.giH, 0
	else
		m2m GdiSI.giW, w
		m2m GdiSI.giH, h
	endif
	push 0	; use GdiSI
  endif
  push giDC		; defDC
  call ImgPaintP
  if usedeb
	.if !eax
		PrintLine Str$("## line %i: image could not be loaded, ", @Line), gdiStatus$(GdiSI.jjLastError)
	.endif
  endif
ENDM
ImgPaintInfo MACRO imgSlot:=<1>, filename:=<CL$()>
  InfoWH=-127
  usedIpp=1
  push InfoWH		; flag w+h needed
  push repargA(filename)
  push imgSlot
  call ImgPaintP	; invoke ImgPaintP, slot, file, handleorflag
ENDM

ImgPaintClr MACRO imgSlot:=<1>
  usedIpp=1
  push 0			; flag clear
  push eax		; dummy
  ifidni <imgSlot>, <all>
	push ImgViewSlots
  else
	push imgSlot
  endif
  call ImgPaintP	; invoke ImgPaintP, slot, file, handleorflag
ENDM

ImgPaint MACRO hCanvas, imgSlot:=<1>, filename:=<CL$()>
  usedIpp=1
  push hCanvas
  push repargA(filename)
  push imgSlot
  call ImgPaintP	; invoke ImgPaintP, ShowBmpCt, optWin, destX, destY, filename
ENDM

PrintCpu MACRO minSSE2:VARARG	; 0=CPU only, -=no CrLf, optional ram, win
Local isWin, isRam, tmp$
	pushad
	SetCpAnsi 1
	sub esp, 124	; create a buffer for the brand string
	mov edi, esp	; point edi to it
	xor ebp, ebp
	.Repeat
		lea eax, [ebp+80000002h]
		db 0Fh, 0A2h	; cpuid 80000002h-80000004h
		stosd
		mov eax, ebx
		stosd
		mov eax, ecx
		stosd
		mov eax, edx
		stosd
		inc ebp
	.Until ebp>=3
	push 1
	pop eax
	db 0Fh, 0A2h	; CPUID 1
	xor ebx, ebx	; CpuSSE, see Intel and OsWiki
	bt edx, 23	; edx bit 23, MMX
	adc ebx, 0	; set bit 0, MMX
	bt edx, 25	; edx bit 25, SSE
	jnc @F
	or ebx, 2	; set bit 1, SSE
@@:	bt edx, 26	; edx bit 26, SSE2
	jnc @F
	or ebx, 4	; set bit 2, SSE2
@@:	bt ecx, 0	; ecx bit 0, SSE3
	jnc @F
	or ebx, 8	; set bit 3, SSE3
@@:	bt ecx, 9	; ecx bit 9, SSSE3
	jnc @F
	or ebx, 16	; set bit 4, SSSE3
@@:	bt ecx, 19	; ecx bit 19, SSE4.1
	jnc @F
	or ebx, 64	; set bit 6, SSE4.1
@@:	bt ecx, 20	; ecx bit 20, SSE4.2
	jnc @F
	or ebx, 128	; set bit 7, SSE4.2
@@:	bt ecx, 28	; ecx bit 28, AVX
	jnc @F
	or ebx, 256	; set bit 8, AVX
@@:	mov edi, esp 	; restore pointer to brand string
	.Repeat				
		.Break .if byte ptr [edi]!=32	; show a string but skip leading blanks
		inc edi
	.Until 0
	.if 0
		ifndef cpuBits
			cpuBits	dd cpuBit0
			cpuBit0	db "MMX", 0
			cpuBit1	db ", SSE", 0
			cpuBit2	db ", SSE2", 0
			ifidni <minSSE2>, <sse2>
				cpuBit3	db "SSE3", 0		; comma removed
			else
				cpuBit3	db ", SSE3", 0
			endif
			cpuBit4	db ", SSSE3", 0
			cpuBit5	db ", movbe", 0
			cpuBit6	db ", SSE4.1", 0
			cpuBit7	db ", SSE4.2", 0
			cpuBit8	db ", AVX", 0
			cpuBit9	db "+OS support", 0
			cpuBit10	db ", pclmulqdq", 0, 0
		endif
	.elseif byte ptr [edi]<32
		Print Chr$("pre-P4")
	.else
		Print edi	; CpuBrand
	.endif
	ifidn <minSSE2>, <0>
		Print
	elseifdifi <minSSE2>, <->
		.if ebx
			Print Chr$(32, 40)	; info on SSE level, 40=(
			isWin=0
			isRam=0
			ifnb <minSSE2>
				isWin INSTR <minSSE2>, <win>
				isRam INSTR <minSSE2>, <ram>
			endif
			if isWin
				Print GetRegVal("HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion","ProductName", "WinXX")
				.if IsFolder(ExpandEnv$("%WinDir%\SysWOW64"))
				  Print " 64, "
				.else
				  Print " 32, "
				.endif
			endif
			if isRam
				push ecx
				sub esp, MEMORYSTATUSEX-4
				push MEMORYSTATUSEX	; set size member
				invoke GlobalMemoryStatusEx, esp
				mov ecx, esp
				mse equ [ecx.MEMORYSTATUSEX]
				Print Str$("%3fGB RAM installed", mse.ullTotalPhys/1.0e9), Str$(", %3fGB available", mse.ullTotalVirtual/1.0e9)
				add esp, MEMORYSTATUSEX
				pop ecx 
			else
					ifidni <minSSE2>, <sse2>
						mov esi, offset cpuBit3
						shr ebx, 3	; skip MMX, SSE1, SSE2
					else
						mov esi, offset cpuBit0
					endif
					.Repeat
						shr ebx, 1
						.if Carry?
						    Print esi
						.endif
						.Repeat
						    lodsb
						.Until !al
					.Until byte ptr [esi]==0
			endif
			Print Chr$(41, 13, 10)	; 41=)
		.endif
	endif
	add esp, 124		; discard brand buffer (after Printing!)
	;  mov [esp+32-4], ebx	; move ebx into eax stack position - returns eax to main for further use
	call MbBufferInit
	popad
ENDM
GetFileProps MACRO file, lg
  ifb <lg>
	push 0
  else
	push lg
  endif
  ifb <file>
	push 0
  else
	push repargA(file)
  endif
  ifndef FileProp$
	Dim FileProp$()
	Enum 0:Lang, Comments, CompanyName, FileDescription, FileVersion, InternalName, LegalCopyright, LegalTrademarks, OriginalFilename, PrivateBuild, 	ProductName, ProductVersion, SpecialBuild
  endif
  push FileProp$(id)
  MbVI PROTO :DWORD, :DWORD, :DWORD
  call MbVI
ENDM
FilePropName$ MACRO ctArg
  push esi
  push edi
  push ecx
  ExternDef txViStrings:BYTE
  mov esi, offset txViStrings
  invoke MbBufferGet
  xchg eax, edi
  mov eax, ctArg
  cdq
  m2m ecx, 13
  div ecx
  mov ecx, edx
  test ecx, ecx
  .if Zero?
	mov eax, Mirror$("Lang")
	stosd
	xchg eax, edi
  .else
	xor edx, edx
	.Repeat
		push edi
		.Repeat
			lodsb
			stosb
		.Until !al
		xchg eax, edi
		pop edi
		inc edx
	.Until edx>ecx
	dec eax
  .endif
  push 1
  push eax
  call MbBufferFix
  pop ecx
  pop edi
  pop esi
  EXITM <( eAx)>
ENDM
TryRTE MACRO lbl, consmode	; TryRTE catchlabel [, con/key/box]
  ExternDef MbRegs32:DWORD
  ifidni <lbl>, <off>
	and MbRegs32, 0
  else
	mov eax, offset MbRegs32+4*9+8
	xchg eax, esp
	push eax
	push offset lbl
	pushad
	push eax	; set flag	
	xchg eax, esp	; restore stack pointer
  endif
  ifidni <consmode>, <key>
	m2m MbFlags[4], 3
  elseifidni <consmode>, <con>
	m2m MbFlags[4], 1
  elseifidni <consmode>, <box>
	and MbFlags[4], 0
  endif
ENDM

TclCtT=1	; 1=TclTry1, MbStrLen	### Try/Catch/Init ###
TclCtC=1	; 1=TclCatch1
TclCtF=0	; Catch only/Finally pairs
MbTcTry$ equ	<>
MbTcCatch$ equ	<>
Try MACRO tcInfo$
  ifndef MbTryCatch
	ifndef guiInit$
		.err <## Try/Catch: Start your code with Init TC ##>
	endif
  endif
  TclCtT=TclCtT+1
  MbCatchCt=TclCtT
  @CatStr(<TclTry>, %TclCtT, <::>)
  .DATA
  ifnb <tcInfo$>
	@CatStr(<TclInfo>, %TclCtT, < db &tcInfo$, 0>)
  else
	@CatStr(<TclInfo>, %TclCtT, < dd 0>)	; lxInfo$
  endif
  .CODE
ENDM

Catch MACRO arg:=<only>
  TclCtC=TclCtC+1
  ifidni <arg>, <only>
	TclCtF=TclCtF+1
	@CatStr(<jmp TclFinally>, %TclCtC)
  endif
  @CatStr(<TclCatch>, %TclCtC, <::>)
ENDM

Finally MACRO
  TclCtF=TclCtF-1
  @CatStr(<TclFinally>, %TclCtC, <::>)
ENDM

TCLE STRUCT
  lxAddr	dd ?	; EXCEPTION_RECORD.ExceptionAddress
  lxCode	dd ?	; EXCEPTION_RECORD.ExceptionCode
  lxWriteFlag	dd ?	; EXCEPTION_RECORD.ExceptionInformation
  lxInfo4	dd ?	; ExceptionInformation[4]
  lxInfo8	dd ?	; ExceptionInformation[8], free for user
  lxInfo$	dd ?	; Try info
TCLE ENDS
LEx equ [esi.TCLE]
ExternDef TryCatchLastEx:TCLE
TcUser equ <TryCatchLastEx.lxInfo8>
LastEx macro arg	; for use with Try/Catch
  ifidni <arg>, <code>
	mov edx, TryCatchLastEx.lxCode
	EXITM <edx>	; Hex$ needs a reg32
  elseifidni <arg>, <line>
	EXITM <MbErrLine>
  elseifidni <arg>, <user>
	mov eax, TryCatchLastEx.lxInfo$
	EXITM <eax>
  elseifidni <arg>, <info>
	ifndef lexFormat
		.DATA
		lexFormat	db "0x%08lx", 0
		lexEIP	db "EIP", 9, 0
		lexCode	db 13, 10, "Code", 9, 0
		.CODE
	endif
	push esi
	push edi
	push ecx
	mov esi, offset TryCatchLastEx
	mov edi, Utf8$(MsgTable$(LEx.lxCode))
	.if Instr_(edi, offset lexFormat)	; first placeholder is EIP
			xchg edx, ecx
			mov edx, LEx.lxAddr
			mov edi, Cat$(Left$(edi, ecx-1)+Hex$(edx)+Mid$(edi, ecx+7))
		.if Instr_(edi, offset lexFormat)	; 2nd placeholder is memory accessed
				xchg edx, ecx
				mov edx, LEx.lxInfo4
				mov edi, Cat$(Left$(edi, ecx-1)+Hex$(edx)+Mid$(edi, ecx+7))
			.if Instr_(edi, "%s")
					xchg edx, ecx
					lea edx, [esi-8-5]	; read
					.if LEx.lxWriteFlag
						add edx, 5		; written
					.endif
					mov edi, Cat$(Left$(edi, ecx-1)+edx+Mid$(edi, ecx+2))
				.endif
			.endif
		.else
			mov edx, LEx.lxAddr
			mov esi, LEx.lxCode		; esi not needed below this point
			mov edi, Cat$(edi+offset lexEIP+Hex$(edx)+offset lexCode+Hex$(esi))
	.endif
	xchg eax, edi
	pop ecx
	pop edi
	pop esi
	EXITM <eax>
  elseifidni <arg>, <flag>
	EXITM <TryCatchLastEx.lxWriteFlag>
  else	; no arg, addr, whatever
	EXITM <TryCatchLastEx.lxAddr>
  endif
ENDM
ErrLineFromMap macro eAdd
  push esi
  push edi
  push ebx
  push eAdd
  lea ecx, [eAdd-401000h]	; mov adjusted EIP to ecx
  mov esi, CL$(0)	; get the executable's name
  mov ebx, Rinstr(esi,".")
  mov edi, Cat$(Left$(esi, ebx)+"map")
  .if Exist(edi)
	TryRTE elfFR	; if MyFile.map exists,
	Let edi=FileRead$(edi)	; read it into edi
elfFR:
	void Rinstr(Cat$(Left$(esi, ebx)+"asc - RichMasm"), "\")	; returns index in edx but pointer in eax
	xchg eax, ebx
	inc ebx
	xchg WinByTitle(ebx, 1), ebx
	mov esi, Instr_(edi, "Line numbers")
	YouCanUseEsi=1
	.if esi
		.Repeat
			inc esi
			mov esi, Instr_(esi, edi, ":")	; 111 0001:00000034
			.Break .if !esi
		.Until Val(Cat$(Mid$(edi, esi+1, 8)+"h"))>=ecx	; get first address above or equal EIP
		.if esi
			sub eax, ecx	; Val returns eax
			push eax	; offset, if any
			.Repeat
				dec esi
			.Until byte ptr [edi+esi]==32	; hit the space
			.Repeat
				dec esi
			.Until byte ptr [edi+esi]<"0"	
			lea eax, [edi+esi+1]	; first digit of line number
			pop ecx
			sub Val(eax), ecx	; subtract popped offset
			mov MbErrLine, eax
			.if ebx
				ifndef NoSendData
				    SendData ebx, Str$("EL=%i", eax)	; inform RichMasm
				endif
			.endif
		.endif
	.endif
  .endif
  pop eAdd
  pop ebx
  pop edi
  pop esi
ENDM
TryCatchEnd MACRO
.DATA
  TclInfo1	db "Len", 0
  TclInfoRead	db "read", 0
  TclInfoWritten	db "written", 0
  TryCatchLastEx TCLE <>
  if TclCtT ne TclCtC
	.err <## Try/Catch pairs unbalanced ##>
  endif
  if TclCtF
	.err <## Catch Only/Finally pairs unbalanced ##>
  endif
EXTERNDEF TclTry1:NEAR	; MbStrLen
EXTERNDEF TclCatch1:NEAR
  While TclCtT
	@CatStr(<dd TclTry>, %TclCtT, <, TclInfo>, %TclCtT, <, TclCatch>, %TclCtT)
	TclCtT=TclCtT-1
  ENDM
  dd 0	; end of table
  .CODE
  MbTryCatch proc 	; pEcxPointers
  	push esi
  	push edi
  	push ebx
	mov ebx, [esp+4+12]	; pEcxPointers
	mov edx, [ebx.EXCEPTION_POINTERS.pExceptionRecord]
	push edx
	mov esi, offset TryCatchLastEx
	mov ecx, [edx.EXCEPTION_RECORD.ExceptionInformation]
	mov LEx.lxWriteFlag, ecx
	mov ecx, [edx.EXCEPTION_RECORD.ExceptionInformation][DWORD]
	mov LEx.lxInfo4, ecx
	mov ecx, [edx.EXCEPTION_RECORD.ExceptionCode]
	mov edx, [edx.EXCEPTION_RECORD.ExceptionAddress]
	push edx
	mov LEx.lxAddr, edx	; set TryCatchLastEx addr, code and info
	mov LEx.lxCode, ecx
	push esi
	add esi, TCLE	; set esi to TclTry1
	fnclex	; get rid of pending FPU exceptions
	ErrLineFromMap edx
	.Repeat
		lodsd
		xor ecx, ecx	; clear user-defined string in case it fails
		test eax, eax	; edx=exception address, >= try, < catch
		.Break .if Zero?
		xchg eax, edi	; edi=try lbl
		lodsd
		xchg eax, ecx	; ecx=ptr to try info
		lodsd		; eax=catch lbl
	.Until edi<=edx && eax>edx	; second condition sets final flag
	pop esi
	pushad
	mov ecx, LEx.lxInfo8
	.if ecx
		Print Str$("[ TcUser=%i ] ", ecx)
	.endif
	popad
	.if !eax
		ExternDef txFatal:BYTE
		if tchMode eq 2
			Inkey offset txFatal, LastEx(info)	; "Fatal error: "
		else
			MsgBox 0, LastEx(info), offset txFatal, MB_OK
		endif
		if usedeb
			Exit debug
		else
			Exit
		endif
		; invoke UnhandledExceptionFilter, addr epx
		; mov eax, [esi+TCLE+8]	; not found? take the first one... (2/2014)
		; mov ecx, [esi+TCLE+4]
	.endif
	mov LEx.lxInfo$, ecx	; zero or ptr to user-defined string
	pop ecx			; ExceptionAddress
	pop esi			; pExceptionRecord
	; edx + edi free
	mov edx, [ebx.EXCEPTION_POINTERS.ContextRecord]
	pop ebx
	pop edi
	if 1			; 5.2.2014, allows "global" catch on top of source !Zero?	; loop exit is edi>Add, not equal
		mov [edx.CONTEXT.regEip], eax		; Try/Catch found, use LastEx(..) to get more info
		if EXCEPTION_CONTINUE_EXECUTION eq -1
			or eax, -1
		else
			mov eax, EXCEPTION_CONTINUE_EXECUTION
		endif
		pop esi
		retn 4
	else
		or byte ptr MbFlags[4], 2	; force wait if console mode
		invoke MbCopy, offset MbDebugBuffer, LastEx(info), -2
		pop esi	; stack balanced again
		push 11	; code use line
		ExternDef MbErrAddLine:NEAR
		jmp MbErrAddLine	; don't care about return address
	endif
  MbTryCatch endp  
ENDM
CodePage$ MACRO arg:=<?>
  push ecx
  sub esp, CPINFOEXW
  push esp
  push 0
  ifidn <arg>, <w>
	call GetACP	; Windows
	push eax
  else
	ifidn <arg>, <?>
		push rv(GetConsoleCP)
	else
		push arg
	endif
  endif
  call GetCPInfoExW
  lea edx, [esp.CPINFOEXW.CodePageName]
  .if !eax
	m2m dword ptr [edx], "?"
  .endif
  push edx
  MbUtf8 PROTO
  call MbUtf8
  add esp, CPINFOEXW
  pop ecx
  EXITM <Use_mov>
ENDM
MbCodePage=1252
MbSetConsole macro
  mov edi, offset MbFlags[-16]	; edi will be zeroed after the macro
  ifidni SubSys, <console>	; RichMasm build has subsys and utf8 info
	ifidn <1>, @Environ(oUtf8)	; Ctrl F6 in RichMasm
		mov eax, CP_UTF8	; either UTF-8...
		mov [edi-16], eax	; SetCpUpperLower$ eax, eax
		mov [edi-12], eax	; -28
	else
		mov eax, MbCodePage	; ... or Windows codepage
	endif
  elseifb SubSys
	invoke GetConsoleWindow	; other builds can use this or GetConsoleCP to check for a console
	.if eax
		mov eax, MbCodePage	; hint to MbPrint: has console
	.endif
  endif
  stosd
  .if eax
	push eax
	invoke SetConsoleCP, eax
	call SetConsoleOutputCP
  .endif
  mov eax, CP_UTF8
  stosd	; MbFlags[-12]
ENDM
Win7Exceptions macro
  if usedeb
	ifidni SubSys, <windows>
		push esi
		xchg rv(LoadLibrary, "kernel32"), esi
		.if rv(GetProcAddress, esi, "GetProcessUserModeExceptionPolicy")
			push eax
			push esp
			call eax
			pop ecx
			test cl, 1
			.if !Zero?
				and ecx, not 1
				push ecx
				call rv(GetProcAddress, esi, "SetProcessUserModeExceptionPolicy")
			.endif
		.endif
		pop esi
	endif
  endif
ENDM
SubSys equ @Environ(oSusy)
usePython=0
useICC=0
IFNDEF Init	; there might be namespace conflicts
Init MACRO args:VARARG
LOCAL tmp$, dllMode, SehOn, iccex
MbInit=1
% echo *** MasmBasic version 31.05.2017 ***
if usedeb
	ifnb <args>
		% echo *** Init args ***
	endif
endif
ifdef True
	@CatStr(<echo ### Warning: True defined as >, %True, < ##>)
else
	True equ -1
endif
ife opattr SQWORD
	if usedeb
		ifnb @Environ(oAssembler)
			% echo *** Warning: SQWORD is unsigned with @Environ(oAssembler) **
		else
			echo * Warning: SQWORD is unsigned with this assembler *
		endif
	endif
	SQWORD equ <QWORD>
endif
.code
ifndef start
	start:
endif
  if useICC
	push useICC
	push INITCOMMONCONTROLSEX
	invoke InitCommonControlsEx, esp
	pop ecx
	pop edx
  endif
  Win7Exceptions	; see W7-64 exceptions if usedeb set
  tchMode=0
  SehOn=0
  dllMode=0
  FOR arg, <args>
	ifidni <arg>, <SEH>
		tchMode=1
	elseifidni <arg>, <python>
		usePython=1
		echo ** using Python **
	elseifidni <arg>, <tc>
		tchMode=1
	elseifidni <arg>, <dll>
		dllMode=1
		pushad
	else
		tmp$ CATSTR <arg>, < >
		is INSTR tmp$, <">
		if is
			ifidni SubSys, <console>
				invoke SetConsoleTitle, repargA(arg)
			endif
		endif
	endif
	if tchMode
		ifidni <arg>, <con>	; 1
			inc MbFlags[4]
			tchMode=2
		elseifidni <arg>, <key>	; 3
			m2m MbFlags[4], 3
		elseifdifi <arg>, <box>	; 0
			ifidni SubSys, <console>	; 1
				inc MbFlags[4]
				tchMode=2
			endif
		endif
		ife SehOn
			SehOn=1
			MbTryCatch PROTO
			invoke SetUnhandledExceptionFilter, offset MbTryCatch	; uses MsgTable etc
			mov MbFlags[8], eax
			if usedeb
				echo *** SEH initialised ***
			endif
		endif
	endif
  ENDM
  if usePython
	Py_Initialize PROTO C
	Py_Finalize PROTO C
	PyRun_SimpleString PROTO C :DWORD
	PyRun_SimpleFile PROTO C :DWORD, :DWORD
	includelib \Python34\libs\python34.lib
	echo ** lib **
	pushad
	call Py_Initialize
	popad
  endif
  fninit
  void Str$(0)
  mov MbFH[-4*12], MbDlevels
  call MbBufferInit
  MbSetConsole
  if dllMode
	popad
  else
	xor esi, esi 	; make sure no reg points to MbHeapTable
	xor edi, edi
	InitLine=@Line
	ife gvPos
		xor ebx, ebx
	else
		SetGlobals	; set ebx to gvStart+128
	endif
  endif
  if gslCt
	gsl_INIT
	gslInit=1
  endif
ENDM
ENDIF
.data
