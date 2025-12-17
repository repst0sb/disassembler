proc WindowProc hWnd,wMsg,wParam,lParam
        mov           eax,[wMsg]
        cmp           eax,WM_DESTROY
        je            .wmDestroy
        invoke        DefWindowProc, [hWnd], [wMsg], [wParam], [lParam]
        jmp           .EndProc

.wmDestroy:
        invoke        PostQuitMessage,0

.EndProc:
        ret
endp

proc Window
        invoke        GetModuleHandle,0
        mov           [wc.hInstance],eax
        invoke        LoadCursor,0,IDC_ARROW
        mov           [wc.hCursor],eax
        invoke        RegisterClass, wc

        invoke        CreateWindowEx,0,_class,_title,WS_VISIBLE+WS_OVERLAPPEDWINDOW,0,0,256,256,NULL,NULL,[wc.hInstance],NULL

.msgLoop:
        invoke        GetMessage, msg, NULL,0,0
        cmp           eax,1
        jb            .EndProc
        jne           .msgLoop
        invoke        DispatchMessage,msg
        jmp           .msgLoop

.EndProc:
        ret
endp