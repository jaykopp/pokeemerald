FernetTown_MapScripts::
	.byte 0


FernetTown_Sign::
	lock
	msgbox FernetTown_Sign_Text_0, MSGBOX_SIGN
	release
	end


FernetTown_Sign_Text_0:
	.string "Fernet Town$"
