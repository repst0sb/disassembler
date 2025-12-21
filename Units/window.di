wc                           WNDCLASS 0,WindowProc,0,0,NULL,NULL,NULL,COLOR_BTNFACE+1,NULL,_class
_class                       du      'DISASSEMBLER', 0
_title                       du      'Disassembler', 0
_edit                        du      'EDIT',0
msg                          MSG
client                       RECT
szFileBin                    du      256 dup 0
szFilterBin                  du      'Bin files',0,'*.bin;*.com',0,0
szFileTxt                    du      256  dup 0
szFilterTxt                  du      'Txt files',0,'*.txt',0,0
ofn1                         OPENFILENAME sizeof.OPENFILENAME, 0,0, szFilterBin,0,0,0,szFileBin,260,0,0,0,0,OFN_ALLOWMULTISELECT+OFN_FILEMUSTEXIST+OFN_EXPLORER,0,0,0,0,0,0
ofn2                         OPENFILENAME sizeof.OPENFILENAME, 0,0, szFilterTxt,0,0,0,szFileTxt,260,0,0,0,0,OFN_ALLOWMULTISELECT+OFN_FILEMUSTEXIST+OFN_EXPLORER,0,0,0,0,0,0




