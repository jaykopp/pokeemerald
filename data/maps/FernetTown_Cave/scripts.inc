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
	msgbox FernetTown_OldLady_Text_0
	releaseall
	end


FernetTown_OldLady_Text_0:
	.string "We used to live in secret, but recently\n"
	.string "more people have discovered this\l"
	.string "place.$"
