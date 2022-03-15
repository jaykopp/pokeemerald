FernetTown_MapScripts::
	.byte 0


FernetTown_Sign::
	lock
	msgbox FernetTown_Sign_Text_0, MSGBOX_SIGN
	release
	end


FernetTown_Girl::
	lock
	faceplayer
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq FernetTown_Girl_2
	msgbox FernetTown_Girl_Text_1
FernetTown_Girl_1:
	releaseall
	end

FernetTown_Girl_2:
	msgbox FernetTown_Girl_Text_0
	goto FernetTown_Girl_1


FernetTown_Sign_Text_0:
	.string "Fernet Town$"

FernetTown_Girl_Text_0:
	.string "Hey guy$"

FernetTown_Girl_Text_1:
	.string "Hey girl$"
