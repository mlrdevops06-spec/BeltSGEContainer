/*
	BeltSGEContainer - Mod de compatibilité DayZ
	Ajoute un slot sur la ceinture SGE Stalker Sunrise pour y attacher
	ON_AContainer1, ON_AContainer2, ON_AContainer3, ON_AContainer4.

	Dépend de: STALKER Equipment (SGE_ClearSky + SGE_Loner) + ON_Container_Pack.
	Optionnel: MH_Artefact_Redux pour les containers à artefacts (Belt_Cont1/2/3).
*/

class CfgPatches
{
	class BeltSGEContainer
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Scripts",
			"SGE_ClearSky",
			"SGE_Loner",
			"ON_Container_Pack",
			"MH_Artefact_Redux"
		};
	};
};

class CfgMods
{
	class BeltSGEContainer
	{
		dir = "BeltSGEContainer";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "Belt SGE Container";
		credits = "";
		author = "";
		authorID = "";
		version = "1.0";
		extra = 0;
		type = "mod";
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = { "BeltSGEContainer/Scripts/4_World" };
			};
		};
	};
};

class CfgVehicles
{
	class SGE_Stalker_Sunrise_Belt;

	class BeltSGEContainer_Sunrise_Belt : SGE_Stalker_Sunrise_Belt
	{
		scope = 2;
		displayName = "Ceinture Sunrise (slot container)";
		// Même slots que la ceinture SGE (Belt_Cont = slot container pour nos ON_AContainer)
		attachments[] =
		{
			"Stalker_Sunrise_Belt_Pouches_L",
			"Stalker_Sunrise_Belt_Pouches_R",
			"Belt_Cont",
			"Med_Pouch"
		};
		class GUIInventoryAttachmentsProps
		{
			class PouchL
			{
				name = "Stalker_Sunrise_Belt_Pouches_L";
				description = "";
				attachmentSlots[] = { "Stalker_Sunrise_Belt_Pouches_L" };
				icon = "set:SGE_icons image:Sunrise_Belt_Pouches";
				section = 1;
			};
			class PouchR
			{
				name = "Stalker_Sunrise_Belt_Pouches_R";
				description = "";
				attachmentSlots[] = { "Stalker_Sunrise_Belt_Pouches_R" };
				icon = "set:SGE_icons image:Sunrise_Belt_Pouches";
				section = 1;
			};
			class Belt_Cont
			{
				name = "Belt_Cont";
				description = "";
				attachmentSlots[] = { "Belt_Cont" };
				icon = "set:SGE_icons image:Belt_Cont";
				section = 1;
			};
			class Med_Pouch
			{
				name = "Med_Pouch";
				description = "";
				attachmentSlots[] = { "Med_Pouch" };
				icon = "set:SGE_icons image:Med_Pouch";
				section = 1;
			};
		};
	};

	class ON_AContainer1;
	class ON_AContainer2;
	class ON_AContainer3;
	class ON_AContainer4;

	class BeltSGEContainer_AContainer1 : ON_AContainer1
	{
		scope = 2;
		displayName = "BeltSGEContainer1";
		inventorySlot[] += { "Belt_Cont" };
	};
	class BeltSGEContainer_AContainer2 : ON_AContainer2
	{
		scope = 2;
		displayName = "BeltSGEContainer2";
		inventorySlot[] += { "Belt_Cont" };
	};
	class BeltSGEContainer_AContainer3 : ON_AContainer3
	{
		scope = 2;
		displayName = "BeltSGEContainer3";
		inventorySlot[] += { "Belt_Cont" };
	};
	class BeltSGEContainer_AContainer4 : ON_AContainer4
	{
		scope = 2;
		displayName = "BeltSGEContainer4";
		inventorySlot[] += { "Belt_Cont" };
	};

	// Containers ceinture SGE : slots Artifacts1/2/3 (ON_Container_Pack), 1 à 3 artefacts Redux
	class SGE_Stalker_Belt_Cont;

	class SGE_Stalker_Belt_Cont1 : SGE_Stalker_Belt_Cont
	{
		scope = 2;
		displayName = "Container ceinture (1 artefact)";
		descriptionShort = "Accepte 1 artefact Redux.";
		attachments[] = { "Artifacts1" };
		itemsCargoSize[] = { 0, 0 };
	};

	class SGE_Stalker_Belt_Cont2 : SGE_Stalker_Belt_Cont
	{
		scope = 2;
		displayName = "Container ceinture (2 artefacts)";
		descriptionShort = "Accepte 2 artefacts Redux.";
		attachments[] = { "Artifacts1", "Artifacts2" };
		itemsCargoSize[] = { 0, 0 };
	};

	class SGE_Stalker_Belt_Cont3 : SGE_Stalker_Belt_Cont
	{
		scope = 2;
		displayName = "Container ceinture (3 artefacts)";
		descriptionShort = "Accepte 3 artefacts Redux.";
		attachments[] = { "Artifacts1", "Artifacts2", "Artifacts3" };
		itemsCargoSize[] = { 0, 0 };
	};
};
