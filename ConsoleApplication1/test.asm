.486
.model flat, stdcall

include drd.inc
includelib drd.lib

;INCLUDE \masm32\include\windows.inc
INCLUDE \masm32\include\kernel32.inc
;INCLUDE \masm32\include\user32.inc
;INCLUDE \masm32\include\advapi32.inc
INCLUDE \masm32\include\msvcrt.inc
;INCLUDE \masm32\include\masm32.inc
INCLUDE \masm32\include\DateTime.inc

;INCLUDE \masm32\macros\macros.asm

;INCLUDELIB \masm32\lib\kernel32.lib
;INCLUDELIB \masm32\lib\user32.lib
;INCLUDELIB \masm32\lib\advapi32.lib
INCLUDELIB \masm32\lib\msvcrt.lib
;INCLUDELIB \masm32\lib\masm32.lib
INCLUDELIB \masm32\lib\DateTime.lib
include \masm32\include\user32.inc
include \masm32\include\gdi32.inc

.data 
pngBoard BYTE "backgammon.bmp",0
pngBlack BYTE "black.bmp",0
pngWhite BYTE "white.bmp",0
pngCube1 BYTE "1.bmp",0
pngCube2 BYTE "2.bmp",0
pngCube3 BYTE "3.bmp",0
pngCube4 BYTE "4.bmp",0
pngCube5 BYTE "5.bmp",0
pngCube6 BYTE "6.bmp",0
objBoard Img <0,0,0,0>
objCube1 Img <0,0,0,0>
objCube2 Img <0,0,0,0>
objCube3 Img <0,0,0,0>
objCube4 Img <0,0,0,0>
objCube5 Img <0,0,0,0>
objCube6 Img <0,0,0,0>
objBlack Img <0,0,0,0>
objWhite Img <0,0,0,0>
white DWORD 0,0,0,0,0,5,0,3,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,2
black DWORD 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 3, 0, 5, 0, 0, 0, 0, 0
dstX1 DWORD 0
dstY1 DWORD 0
cubeValue1  BYTE 0
cubeValue2  BYTE 0

GetLocalTime PROTO :DWORD
.data
LPSYSTEMTIME STRUCT
    wYear       WORD ?
    wMonth      WORD ?
    wDayOfWeek  WORD ?
    wDay        WORD ?
    wHour       WORD ?
    wMinute     WORD ?
    wSecond     WORD ?
    wMilliseconds WORD ?
LPSYSTEMTIME ENDS

localTime LPSYSTEMTIME <>

.code



drawBlackSoldiers PROC
	mov eax, 0
	mov edx, 0
	checkblack1:
		cmp eax, 6
		je checkblack2
		mov ecx, black[eax*4]
		mov ebx, ecx
		imul ebx, 75
		sub ebx, 7
		mov edx, eax
		imul edx, -127
		add edx, 1685
		mov dstX1, edx
		cmp ecx, 0
		jg drawblacksoldiers1
		add eax,1
		jmp checkblack1
	drawblacksoldiers1:
		push eax
		cmp ebx, 60
		jl add1
		invoke drd_imageDraw, offset objBlack, dstX1, ebx
		sub ebx, 75
		pop eax
		jmp drawblacksoldiers1		
	add1:
		pop eax
		mov edx, 0
		add eax, 1
		jmp checkblack1
	
	checkblack2:
		cmp eax, 12
		je checkblack3
		mov ecx, black[eax*4]
		mov ebx, ecx
		imul ebx, 75
		sub ebx, 7
		mov edx, eax
		sub edx, 6
		imul edx, -127
		add edx, 785
		mov dstX1, edx
		cmp ecx, 0
		jg drawblacksoldiers2
		add eax,1
		jmp checkblack2
	drawblacksoldiers2:
		push eax
		cmp ebx, 60
		jl add2
		invoke drd_imageDraw, offset objBlack, dstX1, ebx
		sub ebx, 75
		pop eax
		jmp drawblacksoldiers2		
	add2:
		pop eax
		mov edx, 0
		add eax, 1
		jmp checkblack2

	checkblack3:
		cmp eax, 18
		je checkblack4
		mov ecx, black[eax*4]
		mov ebx, ecx
		imul ebx, 75
		mov dstY1, 1005
		sub dstY1, ebx
		mov ebx, dstY1
		mov edx, eax
		sub edx, 12
		imul edx, 127
		add edx, 150
		mov dstX1, edx
		cmp ecx, 0
		jg drawblacksoldiers3
		add eax,1
		jmp checkblack3
	drawblacksoldiers3:
		push eax
		cmp ebx, 1000
		jg add3
	invoke drd_imageDraw, offset objBlack, dstX1, ebx
		add ebx, 75
		pop eax
		jmp drawblacksoldiers3		
	add3:
		pop eax
		mov edx, 0
		add eax, 1
		jmp checkblack3
	
	checkblack4:
		cmp eax, 24
		je exitblack
		mov ecx, black[eax*4]
		mov ebx, ecx
		imul ebx, 75
		mov dstY1, 1005
		sub dstY1, ebx
		mov ebx, dstY1
		mov edx, eax
		sub edx, 18
		imul edx, 127
		add edx, 1050
		mov dstX1, edx
		cmp ecx, 0
		jg drawblacksoldiers4
		add eax,1
		jmp checkblack4
	drawblacksoldiers4:
		push eax
		cmp ebx, 1000
		jg add4
	invoke drd_imageDraw, offset objBlack, dstX1, ebx
		add ebx, 75
		pop eax
		jmp drawblacksoldiers4		
	add4:
		pop eax
		mov edx, 0
		add eax, 1
		jmp checkblack4
	exitblack:
		ret
drawBlackSoldiers ENDP

drawWhiteSoldiers PROC
	mov eax, 0
	mov edx, 0
	checkwhite1:
		cmp eax, 6
		je checkwhite2
		mov ecx, white[eax*4]
		mov ebx, ecx
		imul ebx, 75
		sub ebx, 7
		mov edx, eax
		imul edx, -127
		add edx, 1685
		mov dstX1, edx
		cmp ecx, 0
		jg drawwhitesoldiers1
		add eax,1
		jmp checkwhite1
	drawwhitesoldiers1:
		push eax
		cmp ebx, 60
		jl addwhite1
		invoke drd_imageDraw, offset objWhite, dstX1, ebx
		sub ebx, 75
		pop eax
		jmp drawwhitesoldiers1		
	addwhite1:
		pop eax
		mov edx, 0
		add eax, 1
		jmp checkwhite1
	
	checkwhite2:
		cmp eax, 12
		je checkwhite3
		mov ecx, white[eax*4]
		mov ebx, ecx
		imul ebx, 75
		sub ebx, 7
		mov edx, eax
		sub edx, 6
		imul edx, -127
		add edx, 785
		mov dstX1, edx
		cmp ecx, 0
		jg drawwhitesoldiers2
		add eax,1
		jmp checkwhite2
	drawwhitesoldiers2:
		push eax
		cmp ebx, 60
		jl addwhite2
		invoke drd_imageDraw, offset objWhite, dstX1, ebx
		sub ebx, 75
		pop eax
		jmp drawwhitesoldiers2		
	addwhite2:
		pop eax
		mov edx, 0
		add eax, 1
		jmp checkwhite2

	checkwhite3:
		cmp eax, 18
		je checkwhite4
		mov ecx, white[eax*4]
		mov ebx, ecx
		imul ebx, 75
		mov dstY1, 1005
		sub dstY1, ebx
		mov ebx, dstY1
		mov edx, eax
		sub edx, 12
		imul edx, 127
		add edx, 150
		mov dstX1, edx
		cmp ecx, 0
		jg drawwhitesoldiers3
		add eax,1
		jmp checkwhite3
	drawwhitesoldiers3:
		push eax
		cmp ebx, 1000
		jg addwhite3
	invoke drd_imageDraw, offset objWhite, dstX1, ebx
		add ebx, 75
		pop eax
		jmp drawwhitesoldiers3		
	addwhite3:
		pop eax
		mov edx, 0
		add eax, 1
		jmp checkwhite3
	
	checkwhite4:
		cmp eax, 24
		je exitwhite
		mov ecx, white[eax*4]
		mov ebx, ecx
		imul ebx, 75
		mov dstY1, 1005
		sub dstY1, ebx
		mov ebx, dstY1
		mov edx, eax
		sub edx, 18
		imul edx, 127
		add edx, 1050
		mov dstX1, edx
		cmp ecx, 0
		jg drawwhitesoldiers4
		add eax,1
		jmp checkwhite4
	drawwhitesoldiers4:
		push eax
		cmp ebx, 1000
		jg addwhite4
	invoke drd_imageDraw, offset objWhite, dstX1, ebx
		add ebx, 75
		pop eax
		jmp drawwhitesoldiers4		
	addwhite4:
		pop eax
		mov edx, 0
		add eax, 1
		jmp checkwhite4
	

	exitwhite:
		ret
drawWhiteSoldiers ENDP


rollCube PROC
	invoke GetLocalTime, ADDR localTime  
	mov ax, localTime.wMilliseconds 
	mov bl, 167
	div bl
	mov cubeValue1, al
	mov ax, localTime.wMilliseconds 
	mov bl, 6
	div bl
	mov cubeValue2, ah
	ret
rollCube ENDP

drawCube1 PROC
	cmp cubeValue1, 3
	jl lowFirstCube
	cmp cubeValue1, 4
	jl FirstCube4
	cmp cubeValue1, 5
	je FirstCube6
	invoke drd_imageDraw, offset objCube5, 895, 450
	ret
	lowFirstCube:
		cmp cubeValue1, 1
		jl FirstCube1
		cmp cubeValue1, 2
		je FirstCube3
		push ax
		invoke drd_imageDraw, offset objCube2, 895, 450
		pop ax
		ret
	FirstCube1: 
		push ax
		invoke drd_imageDraw, offset objCube1, 895, 450
		pop ax
		ret
	FirstCube3: 
		push ax
		invoke drd_imageDraw, offset objCube3, 895, 450
		pop ax
		ret
	FirstCube4: 
		push ax
		invoke drd_imageDraw, offset objCube4, 895, 450
		pop ax
		ret
	FirstCube6: 
		push ax
		invoke drd_imageDraw, offset objCube6, 895, 450
		pop ax
		ret
drawCube1 ENDP

drawCube2 PROC
	cmp cubeValue2, 3
		jl lowSecondCube
		cmp cubeValue2, 4
		jl SecondCube4
		cmp cubeValue2, 5
		je SecondCube6
		invoke drd_imageDraw, offset objCube5, 895, 750
		ret
	lowSecondCube:
		cmp cubeValue2, 1
		jl SecondCube1
		cmp cubeValue2, 2
		je SecondCube3
		push ax
		invoke drd_imageDraw, offset objCube2, 895, 750
		pop ax
		ret
	SecondCube1: 
		push ax
		invoke drd_imageDraw, offset objCube1, 895, 750
		pop ax
		ret
	SecondCube3: 
		push ax
		invoke drd_imageDraw, offset objCube3, 895, 750
		pop ax
		ret
	SecondCube4: 
		push ax
		invoke drd_imageDraw, offset objCube4, 895, 750
		pop ax
		ret
	SecondCube6: 
		push ax
		invoke drd_imageDraw, offset objCube6, 895, 750
		pop ax
		ret
drawCube2 ENDP
	
drawCube PROC
	invoke drawCube1
	invoke drawCube2
	ret
drawCube ENDP
	
drawsoldiers PROC
	invoke drawBlackSoldiers
	invoke drawWhiteSoldiers
	invoke drawCube
	ret
drawsoldiers ENDP

handleKey PROC
    invoke GetAsyncKeyState, 32
    INVOKE rollCube
    ret

handleKey ENDP

main proc
	invoke drd_init, 1920, 1080, 0
	INVOKE rollCube
	invoke drd_imageLoadFile,offset pngBoard, offset objBoard
	invoke drd_imageLoadFile,offset pngCube1, offset objCube1
	invoke drd_imageLoadFile,offset pngCube2, offset objCube2
	invoke drd_imageLoadFile,offset pngCube3, offset objCube3
	invoke drd_imageLoadFile,offset pngCube4, offset objCube4
	invoke drd_imageLoadFile,offset pngCube5, offset objCube5
	invoke drd_imageLoadFile,offset pngCube6, offset objCube6
	invoke drd_imageLoadFile,offset pngBlack, offset objBlack
	invoke drd_imageLoadFile,offset pngWhite, offset objWhite
	loopa:
		invoke drd_imageDraw, offset objBoard, 0, 0
		;invoke drd_imageDraw, offset objCube1, 895, 450
		invoke drawsoldiers
		invoke drd_processMessages
		invoke drd_flip
		invoke drd_setKeyHandler, handleKey
	jmp loopa
main endp
END main