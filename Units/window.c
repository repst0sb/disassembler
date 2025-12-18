proc WindowProc uses ebx esi edi, hWnd,wMsg,wParam,lParam
        mov           eax,[wMsg]
        cmp           eax, WM_CREATE
        je            .wmCreate
        cmp           eax, WM_SIZE
        je            .wmSize
        cmp           eax, WM_SETFOCUS
        je            .wmSetFocus
        cmp           eax, WM_COMMAND
        je            .wmCommand
        cmp           eax,WM_DESTROY
        je            .wmDestroy

.defwndproc:
        invoke        DefWindowProc, [hWnd], [wMsg], [wParam], [lParam]
        jmp           .EndProc

.wmCreate:
        invoke        GetClientRect,[hWnd],client
        invoke        CreateWindowEx,WS_EX_CLIENTEDGE,_edit,0,WS_VISIBLE+WS_CHILD+WS_HSCROLL+WS_VSCROLL+ES_AUTOHSCROLL+ES_AUTOVSCROLL+ES_MULTILINE,[client.left],[client.top],[client.right],[client.bottom],[hWnd],0,[wc.hInstance],NULL
        or            eax,eax
        jz            .failed
        mov           [edithWnd],eax
        invoke        CreateFont,99,0,0,0,0,FALSE,FALSE,FALSE,DEFAULT_CHARSET,OUT_RASTER_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,FIXED_PITCH+FF_DONTCARE,NULL
        or            eax,eax
        jz            .failed
        mov           [editFont],eax
        invoke        SendMessage,[edithWnd],WM_SETFONT,eax,FALSE
        jmp           .EndProc

.failed:
        or             eax,-1
        jmp           .EndProc

.wmSize:
        invoke        GetClientRect,[hWnd],client
        invoke        MoveWindow,[edithWnd],[client.left],[client.top],[client.right],[client.bottom],TRUE
        xor           eax,eax
        jmp           .EndProc

.wmSetFocus:
        invoke        SetFocus,[edithWnd]
        xor           eax,eax
        jmp           .EndProc

.wmCommand:
        mov           eax,[wParam]
        and           eax,0FFFFh
        cmp           eax,IDM_INPUT
        je            .input
        cmp           eax,IDM_OUTPUT
        je            .output
        cmp           eax,IDM_EXIT
        je            .wmDestroy
        jmp           .defwndproc
.input:
        jmp           .EndProc

.output:
        jmp           .EndProc

.wmDestroy:
        invoke        DeleteObject,[editFont]
        invoke        PostQuitMessage,0
        xor           eax, eax

.EndProc:
        ret
endp

proc Window
        invoke        GetModuleHandle,0
        mov           [wc.hInstance],eax
        invoke        LoadCursor,0,IDC_ARROW
        mov           [wc.hCursor],eax
        invoke        RegisterClass, wc

        invoke        LoadMenu,[wc.hInstance],IDR_MENU
        invoke        CreateWindowEx,0,_class,_title,WS_VISIBLE+WS_OVERLAPPEDWINDOW+WS_MAXIMIZE ,0,0,500,500,NULL,eax,[wc.hInstance],NULL

.msgLoop:
        invoke        GetMessage, msg, NULL,0,0
        cmp           eax,1
        jb            .EndProc
        jne           .msgLoop
        invoke        TranslateMessage,msg
        invoke        DispatchMessage,msg
        jmp           .msgLoop

.EndProc:
        ret
endp