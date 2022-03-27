FernetTown_Cave_MapScripts::
	.byte 0


FernetTown_OldLady::
	lockall
	faceplayer
	msgbox FernetTown_OldLady_Text_0
	releaseall
	end


FernetTown_Guard::
	lockall
	faceplayer
	msgbox FernetTown_Guard_Text_0
	releaseall
	end


FernetTown_OldLady_Text_0:
	.string "We used to live in secret, but recently\n"
	.string "more people have discovered this\l"
	.string "place.$"

FernetTown_Guard_Text_0:
	.string "I'm sorry, but I cannot allow you to\n"
	.string "enter before you have proven yourself\l"
	.string "worthy.$"
