#NoTrayIcon 
#SingleInstance ignore

; use outputs from touchscreen to fire off display mode change commands
F24::run displayswitch.exe /clone
F23::run displayswitch.exe /extend

; display popup if they try to use Win+p to change display mode
#p::MsgBox, Please use touchscreen to change display mode