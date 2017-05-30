.486
.model flat, stdcall

include drd.inc
includelib drd.lib

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
		je exit
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
	

	exit:
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
		invoke drd_imageDraw, offset objwhite, dstX1, ebx
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
		invoke drd_imageDraw, offset objwhite, dstX1, ebx
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
	invoke drd_imageDraw, offset objwhite, dstX1, ebx
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
	invoke drd_imageDraw, offset objwhite, dstX1, ebx
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

drawsoldiers PROC
	invoke drawBlackSoldiers
	invoke drawWhiteSoldiers
	ret
drawsoldiers ENDP

main proc
	invoke drd_init, 1920, 1080, 0
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
	jmp loopa
main endp
END main