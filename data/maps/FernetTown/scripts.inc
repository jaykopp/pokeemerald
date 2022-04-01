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
	setvar VAR_FERNET_TOWN_ELDER, 0
	msgbox FernetTown_Girl_Text_0
	release
	end


FernetTown_Marcus::
	trainerbattle_single TRAINER_MARCUS, FernetTown_Marcus_Text_0, FernetTown_Marcus_Text_1
	msgbox FernetTown_Marcus_Text_2, MSGBOX_AUTOCLOSE
	end


FernetTown_Sign_Text_0:
	.string "Fernet Town$"

FernetTown_Girl_Text_0:
	.string "The var has been set to 0.$"

FernetTown_Marcus_Text_0:
	.string "Fight me!$"

FernetTown_Marcus_Text_1:
	.string "Whaaaaa!$"

FernetTown_Marcus_Text_2:
	.string "You are dead to me.$"
