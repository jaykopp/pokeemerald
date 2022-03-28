FernetTown_PlayersHouse_MapScripts::
	.byte 0


FernetTown_PlayersHouse_Dad::
	lockall
	faceplayer
	setflag FLAG_SYS_B_DASH
	msgbox FernetTown_PlayersHouse_Dad_Text_0
	releaseall
	end


FernetTown_PlayersHouse_Dad_Text_0:
	.string "I hope your journey will help you grow\n"
	.string "as a person. Here is a pair of RUNNING\l"
	.string "SHOES.$"
