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
pngBlackWin BYTE "blackWin.bmp",0
pngWhiteWin BYTE "whiteWin.bmp",0
objBoard Img <0,0,0,0>
objCube1 Img <0,0,0,0>
objCube2 Img <0,0,0,0>
objCube3 Img <0,0,0,0>
objCube4 Img <0,0,0,0>
objCube5 Img <0,0,0,0>
objCube6 Img <0,0,0,0>
objBlack Img <0,0,0,0>
objWhite Img <0,0,0,0>
objBlackWin Img <0,0,0,0>
objWhiteWin Img <0,0,0,0>
white DWORD 0,0,0,0,0,5,0,3,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,2
black DWORD 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 3, 0, 5, 0, 0, 0, 0, 0
dstX1 DWORD 0
dstY1 DWORD 0
BlackEat DWORD 0
WhitesEat DWORD 0
cubeValue1  BYTE 0
cubeValue2  BYTE 0
TurnsForCube1 BYTE 0
TurnsForCube2 BYTE 0
turn DWORD 0
NumBlack DWORD 0
NumWhite DWORD 0
BlackWin DWORD 0
WhiteWin DWORD 0
Index DWORD 0
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
	
	mov edx, 0
	cmp BlackEat, 0
	jg eatBlack
	mov eax, 0
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
	eatBlack:
		
   		cmp eax, 0
		je checkblack1
		invoke drd_imageDraw, offset objBlack, 915, 175
		sub eax, 1
		jmp eatBlack
	exitblack:
		ret
drawBlackSoldiers ENDP

drawWhiteSoldiers PROC
	mov edx, 0
	mov eax, WhitesEat
	cmp WhitesEat, 0
	jg eatWhite
	mov eax, 0
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
	eatWhite:
		
   		cmp eax, 0
		je checkwhite1
		invoke drd_imageDraw, offset objWhite, 915, 945
		sub eax, 1
		jmp eatWhite
	exitwhite:
		ret
drawWhiteSoldiers ENDP


rollCube PROC
	mov TurnsForCube1, 1
	mov TurnsForCube2, 1
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
	invoke drd_imageDraw, offset objCube5, 900, 450
	ret
	lowFirstCube:
		cmp cubeValue1, 1
		jl FirstCube1
		cmp cubeValue1, 2
		je FirstCube3
		push ax
		invoke drd_imageDraw, offset objCube2, 900, 450
		pop ax
		ret
	FirstCube1: 
		push ax
		invoke drd_imageDraw, offset objCube1, 900, 450
		pop ax
		ret
	FirstCube3: 
		push ax
		invoke drd_imageDraw, offset objCube3, 900, 450
		pop ax
		ret
	FirstCube4: 
		push ax
		invoke drd_imageDraw, offset objCube4, 900, 450
		pop ax
		ret
	FirstCube6: 
		push ax
		invoke drd_imageDraw, offset objCube6, 900, 450
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
		invoke drd_imageDraw, offset objCube5, 910, 555
		ret
	lowSecondCube:
		cmp cubeValue2, 1
		jl SecondCube1
		cmp cubeValue2, 2
		je SecondCube3
		push ax
		invoke drd_imageDraw, offset objCube2, 910, 555
		pop ax
		ret
	SecondCube1: 
		push ax
		invoke drd_imageDraw, offset objCube1, 910, 555
		pop ax
		ret
	SecondCube3: 
		push ax
		invoke drd_imageDraw, offset objCube3, 910, 555
		pop ax
		ret
	SecondCube4: 
		push ax
		invoke drd_imageDraw, offset objCube4, 910, 555
		pop ax
		ret
	SecondCube6: 
		push ax
		invoke drd_imageDraw, offset objCube6, 910, 555
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
playBlackSoldiers PROC
  	mov eax, 0
 	mov ebx, -1
	mov edx, 0
	mov ecx, -1
	cmp WhiteWin, 1
	je return
	cmp BlackWin, 1
	je return
	mov al, cubeValue2
	mov dl, cubeValue1
	mov Index, 0
	cmp BlackEat, 0
	jg procceseatenblack
	;mov Index, 0
	;cmp WhitesEat, 0
	;jg getoutblack
	checkSoldiersBlackCube2:
		cmp TurnsForCube2, 0
		je checkSoldiersBlackCube1
		add ebx, 1
		cmp ebx, 23
		jg checkSoldiersBlackCube1
		cmp black[ebx*4], 0
		jg moveSoldiersBlackCube2
		jmp checkSoldiersBlackCube2
	moveSoldiersBlackCube2:
		add eax, 1
		add eax, ebx
		cmp white[eax*4] , 1
		jg noplaceblackCube2
		cmp white[eax*4] , 1
		je eatwhite1
		cmp eax, 23
		jg pushOutBlackCube2
		add black[eax*4] , 1
	pushOutBlackCube2:
		sub black[ebx*4] , 1
		sub TurnsForCube2, 1
		mov ebx, -1
		mov eax, 0
		mov al, cubeValue2
		jmp checkSoldiersBlackCube2
	eatwhite1:
		add WhitesEat, 1
		sub white[eax*4] , 1
		add black[eax*4] , 1
		sub black[ebx*4] , 1
		sub TurnsForCube2, 1
		cmp TurnsForCube2, 0
		jne checkSoldiersBlackCube2

	checkSoldiersBlackCube1:
		cmp TurnsForCube1, 0
		je getoutblack
		add ecx, 1
		cmp ecx, 23
		jg getoutblack
		cmp black[ecx*4], 0
		jg moveSoldiersBlackCube1
		jmp checkSoldiersBlackCube1
	moveSoldiersBlackCube1:
		add edx, 1
		add edx, ecx
		cmp white[edx*4] , 1
		jg noplaceblackCube1
			
		cmp white[edx*4] , 1
		je eatwhite2
		cmp edx, 23
		jg pushOutBlackCube1
		add black[edx*4] , 1
	pushOutBlackCube1:
		sub black[ecx*4] , 1

		sub TurnsForCube1, 1
		mov ecx, -1
		mov edx, 0
		mov dl, cubeValue1
		jmp checkSoldiersBlackCube1
	eatwhite2:
		add WhitesEat, 1
		sub white[edx*4] , 1
		add black[edx*4] , 1
		sub black[ecx*4] , 1
		sub TurnsForCube1, 1
		cmp TurnsForCube1, 0
		jne checkSoldiersBlackCube1
		getoutblack:
		mov ebx, NumBlack
			jmp checkBlackWin
			ret
	checkBlackWin:
		cmp Index, 24
		je SetBlackWin 
		mov eax, Index
		add ebx, black[eax*4]
		
		add Index, 1
		jmp checkBlackWin

		SetBlackWin: 
		cmp ebx, 0
		jg return
		cmp BlackEat, 0
		jg return
		mov BlackWin, 1
		ret

		return:
		ret
		
	procceseatenblack:
		procceseatenblackcube2:
			add ebx, 1
			cmp ebx, 5
			jg procceseatenblackcube1
			add eax, ebx
			cmp white[eax*4] , 1
			jg procceseatenblackcube1
			cmp white[eax*4] , 1
			je eatfromeatenwhite1
			sub BlackEat, 1
			add black[eax*4], 1
			sub TurnsForCube2, 1
			cmp BlackEat, 0
			jg procceseatenblackcube1
			jmp checkSoldiersBlackCube2

			eatfromeatenwhite1:
			add WhitesEat, 1
			sub white[eax*4] , 1
			add black[eax*4] , 1
			sub BlackEat, 1
			sub TurnsForCube2, 1
			jmp checkSoldiersBlackCube2
		procceseatenblackcube1:
			add ecx, 1
			cmp ecx, 5
			jg getoutblack
			add edx, ecx
			cmp white[edx*4] , 1
			jg getoutblack
			cmp white[edx*4] , 1
			je eatfromeatenwhite2
			sub BlackEat, 1
			add black[edx*4], 1
			sub TurnsForCube1, 1
			jmp checkSoldiersBlackCube2
	
			eatfromeatenwhite2:
			add WhitesEat, 1
			sub white[edx*4] , 1
			add black[edx*4] , 1
			sub BlackEat, 1
			sub TurnsForCube1, 1
			jmp checkSoldiersBlackCube2

	cmp turn, 1
	je blackTurn
	mov turn, 1
	ret
	blackTurn:
		mov turn, 0
	ret

	noplaceblackCube2:
				mov al, cubeValue2
				jmp checkSoldiersBlackCube2

	noplaceblackCube1:
				mov dl, cubeValue1
				jmp checkSoldiersBlackCube1
playBlackSoldiers ENDP

playWhiteSoldiers PROC
	mov eax, 23
 	mov ebx, 24
	mov edx, 23
	mov ecx, 24
	cmp WhiteWin, 1
	je return
	cmp BlackWin, 1
	je return
	mov al, cubeValue2
	mov dl, cubeValue1
	mov Index, 0
	cmp WhitesEat, 0
	jg procceseatenwhite
	; Cube 2
	checkSoldiersWhiteCube2:
		cmp TurnsForCube2, 0
		je checkSoldiersWhiteCube1
		sub ebx, 1
		cmp ebx, 0
		jl checkSoldiersWhiteCube1
		cmp white[ebx*4], 0
		jg moveSoldiersWhiteCube2
		jmp checkSoldiersWhiteCube2
	moveSoldiersWhiteCube2:
		add eax, 1
		push edx
		mov edx, ebx
		sub edx, eax
		mov eax, edx
		pop edx
		cmp black[eax*4] , 1
		jg noplacewhiteCube2
		cmp black[eax*4] , 1
		je eatblack1
		cmp eax, 0
		jl pushOutWhiteCube2
		add white[eax*4] , 1
	pushOutWhiteCube2:
		sub white[ebx*4] , 1
		mov dl, cubeValue1
		sub TurnsForCube2, 1
		mov ebx, 24
		mov eax, 0
		mov al, cubeValue2
		jmp checkSoldiersWhiteCube2
	eatblack1:
		add BlackEat, 1
		sub black[eax*4] , 1
		add white[eax*4] , 1
		sub white[ebx*4] , 1
		sub TurnsForCube2, 1
		cmp TurnsForCube2, 0
		jg checkSoldiersWhiteCube2
	; Cube 1
	checkSoldiersWhiteCube1:
		cmp TurnsForCube1, 0
		je getoutwhite
		sub ecx, 1
		cmp ecx, 0
		jl getoutwhite
		cmp white[ecx*4], 0
		jg moveSoldiersWhiteCube1
		jmp checkSoldiersWhiteCube1
	moveSoldiersWhiteCube1:
		add edx, 1
		push eax
		mov eax, ecx
		sub eax, edx
		mov edx, eax
		pop eax
		cmp black[edx*4] , 1
		jg noplacewhiteCube1
		cmp black[edx*4] , 1
		je eatblack2
		cmp edx, 0
		jl pushOutWhiteCube1
		add white[edx*4] , 1
	pushOutWhiteCube1:
		sub white[ecx*4] , 1
		sub TurnsForCube1, 1
		mov ecx, 24
		mov edx, 0 
		mov dl, cubeValue1
		jmp checkSoldiersWhiteCube1
	eatblack2:
		add BlackEat, 1
		sub black[edx*4] , 1
		add white[edx*4] , 1
		sub white[ecx*4] , 1
		sub TurnsForCube1, 1
		cmp TurnsForCube1, 0
		jg checkSoldiersWhiteCube1
	getoutwhite:
		mov ebx, NumWhite
			jmp checkWhiteWin
			ret
	checkWhiteWin:
		cmp Index, 24
		je SetWhitekWin 
		mov eax, Index
		add ebx, white[eax*4]
		
		add Index, 1
		jmp checkWhiteWin

		SetWhitekWin: 
		cmp ebx, 0
		jg return
		cmp WhitesEat, 0
		jg return
		mov WhiteWin, 1
		ret

	return:
		ret 

	cmp turn, 1
	je whiteTurn
	mov turn, 1
	ret
	whiteTurn:
		mov turn, 0
	ret
	
	procceseatenwhite:
		procceseatenwhitecube2:
			sub ebx, 1
			cmp ebx, 18
			jl procceseatenwhitecube1
			push edx
			mov edx, ebx
			sub edx, eax
			mov eax, edx
			pop edx
			;sub eax, edx
			cmp black[eax*4] , 1
			jg procceseatenwhitecube1
			cmp black[eax*4] , 1
			je eatfromeatenblack1
			sub WhitesEat, 1
			add white[eax*4], 1
			sub TurnsForCube2, 1
			cmp WhitesEat, 0
			jg procceseatenwhitecube1
			jmp checkSoldiersWhiteCube2

			eatfromeatenblack1:
			add BlackEat, 1
			sub black[eax*4] , 1
			add white[eax*4] , 1
			sub WhitesEat, 1
			sub TurnsForCube2, 1
			jmp checkSoldiersWhiteCube2
		
		procceseatenwhitecube1:
			sub ecx, 1
			cmp ecx, 18
			jl getoutwhite
			push eax
			mov eax, ecx
			sub eax, edx
			mov edx, eax
			pop eax
			cmp black[edx*4] , 1
			jg getoutwhite
			cmp black[edx*4] , 1
			je eatfromeatenblack2
			sub WhitesEat, 1
			add white[edx*4], 1
			sub TurnsForCube1, 1
			jmp checkSoldiersWhiteCube2
		
			eatfromeatenblack2:
			add BlackEat, 1
			sub black[edx*4] , 1
			add white[edx*4] , 1
			sub WhitesEat, 1
			sub TurnsForCube1, 1
			jmp checkSoldiersWhiteCube2
	
	
	
	noplacewhiteCube2:
				mov al, cubeValue2
				jmp checkSoldiersWhiteCube2

	noplacewhiteCube1:
				mov dl, cubeValue1
				jmp checkSoldiersWhiteCube1
playWhiteSoldiers ENDP


handleKey PROC
    invoke GetAsyncKeyState, 32
    INVOKE rollCube

	;Check turns
	cmp turn, 1
	je whiteTurn
	mov turn, 1
	jmp playBlackTurn
	whiteTurn:
		mov turn, 0
		jmp playWhiteTurn

	playBlackTurn:	
		mov al, cubeValue1
		cmp al, cubeValue2
		jne playSingleCubeblack
		mov TurnsForCube1, 2
		mov TurnsForCube2, 2
		playSingleCubeblack:
			invoke playBlackSoldiers
		ret
	playWhiteTurn:
		mov al, cubeValue1
		cmp al, cubeValue2
		jne playSingleCubewhite
		mov TurnsForCube1, 2
		mov TurnsForCube2, 2
		playSingleCubewhite:
			invoke playWhiteSoldiers
		ret
		 
handleKey ENDP
drawMessages PROC
	cmp BlackWin, 1
	je drawBlackWin
	cmp WhiteWin, 1
	je drawWhiteWin
	ret

	drawBlackWin:
		invoke drd_imageDraw, offset objBlackWin, 130, 65
		ret
	drawWhiteWin:
		invoke drd_imageDraw, offset objWhiteWin, 130, 65
		ret
drawMessages ENDP
main proc
	;mov BlackEat, 2
	invoke drd_init, 1920, 1080, 0
	invoke rollCube
	invoke drd_imageLoadFile,offset pngBoard, offset objBoard
	invoke drd_imageLoadFile,offset pngCube1, offset objCube1
	invoke drd_imageLoadFile,offset pngCube2, offset objCube2
	invoke drd_imageLoadFile,offset pngCube3, offset objCube3
	invoke drd_imageLoadFile,offset pngCube4, offset objCube4
	invoke drd_imageLoadFile,offset pngCube5, offset objCube5
	invoke drd_imageLoadFile,offset pngCube6, offset objCube6
	invoke drd_imageLoadFile,offset pngBlack, offset objBlack
	invoke drd_imageLoadFile,offset pngWhite, offset objWhite
	invoke drd_imageLoadFile,offset pngBlackWin, offset objBlackWin
	invoke drd_imageLoadFile,offset pngWhiteWin, offset objWhiteWin
	loopa:
		invoke drd_imageDraw, offset objBoard, 0, 0
		;invoke drd_imageDraw, offset objCube1, 895, 450
		invoke drawsoldiers
		invoke drawMessages
		invoke drd_processMessages
		invoke drd_flip
		invoke drd_setKeyHandler, handleKey
		
	jmp loopa
main endp
END main