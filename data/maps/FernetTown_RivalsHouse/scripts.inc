FernetTown_RivalsHouse_MapScripts::
	.byte 0


FernetTown_RivalsHouse_OldMan::
	lock
	faceplayer
	msgbox FernetTown_RivalsHouse_OldMan_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq FernetTown_RivalsHouse_OldMan_2
	givemon SPECIES_MACHOP, 5, ITEM_ORAN_BERRY
	compare VAR_RESULT, 0
	goto_if_eq FernetTown_RivalsHouse_OldMan_5
	compare VAR_RESULT, 1
	goto_if_eq FernetTown_RivalsHouse_OldMan_6
	goto Common_EventScript_NoMoreRoomForPokemon
FernetTown_RivalsHouse_OldMan_1:
	releaseall
	end

FernetTown_RivalsHouse_OldMan_2:
	msgbox FernetTown_RivalsHouse_OldMan_Text_1
	goto FernetTown_RivalsHouse_OldMan_1

FernetTown_RivalsHouse_OldMan_5:
	call FernetTown_RivalsHouse_Fanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq FernetTown_RivalsHouse_OldMan_10
	goto FernetTown_RivalsHouse_OldMan_1

FernetTown_RivalsHouse_OldMan_6:
	call FernetTown_RivalsHouse_Fanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq FernetTown_RivalsHouse_OldMan_13
FernetTown_RivalsHouse_OldMan_12:
	call Common_EventScript_TransferredToPC
	goto FernetTown_RivalsHouse_OldMan_1

FernetTown_RivalsHouse_OldMan_10:
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto FernetTown_RivalsHouse_OldMan_1

FernetTown_RivalsHouse_OldMan_13:
	call Common_EventScript_NameReceivedPartyMon
	goto FernetTown_RivalsHouse_OldMan_12


FernetTown_RivalsHouse_Fanfare::
	bufferspeciesname 1, SPECIES_MACHOP
	playfanfare MUS_CAUGHT
	message FernetTown_RivalsHouse_Fanfare_Text_0
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_MACHOP
	return


FernetTown_RivalsHouse_OldMan_Text_0:
	.string "Want a pokemon?$"

FernetTown_RivalsHouse_OldMan_Text_1:
	.string "No worries.$"

FernetTown_RivalsHouse_Fanfare_Text_0:
	.string "{PLAYER} obtained Machop!$"
