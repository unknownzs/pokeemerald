IJburg_FrenkiesHouse_Indoor_MapScripts::
	.byte 0


@ State descriptions for VAR_IJBURG_STATE
	@ 1: Got
	@ 2: Got Pokemon
	@ 3: Received Pokedex
	@ 4: Received Running Shoes

IJburg_EventScript_TalkToProf::
	lockall
    faceplayer
	goto_if_ne VAR_IJBURG_STATE, 0, IJburg_EventScript_FindPokemon
	goto_if_ne VAR_IJBURG_STATE, 1, IJburg_EventScript_FoundPokemonQuestion
	goto_if_ne VAR_IJBURG_STATE, 2, IJburg_EventScript_GetPokedex
	goto_if_ne VAR_IJBURG_STATE, 3, IJburg_EventScript_Talk
	releaseall
	end

IJburg_EventScript_FindPokemon::
	msgbox IJburg_Text_FindStarter, MSGBOX_DEFAULT
	setvar VAR_IJBURG_STATE, 1
    end

IJburg_EventScript_FoundPokemonQuestion::
	msgbox IJburg_Text_FoundPokemonQuestion, MSGBOX_DEFAULT
    end

IJburg_EventScript_GetPokedex::
	setvar VAR_IJBURG_STATE, 3

IJburg_Text_FoundPokemonQuestion::
	.string "Have you found the troublemaker?/n"
	.string "Find him and you can keep him!$"

IJburg_Text_ChooseStarter::
	.string "Please help me!/n"
	.string "Will you help me?"/n"
	.string "I do not know what has happend!/n"
	.string "Somehow all pokemons got loose!/n"
	.string "If you can find the Pokemon who is responsible for this,/n"
	.string "I will let you keep that troublemaker$"

IJburg_EventScript_Talk::
	.string "Frenkie is not here!"
	