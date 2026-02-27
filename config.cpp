/*
	BeltSGEContainer - Mod de compatibilité DayZ
	Ajoute un slot sur la ceinture SGE Stalker Sunrise pour y attacher
	ON_AContainer1, ON_AContainer2, ON_AContainer3, ON_AContainer4.

	Dépend de: STALKER Equipment (addons SGE_ClearSky + Stalker) + STALKER Containers Pack
	Ceinture et slots lus depuis addons\Stalker\config.
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
			"ON_Container_Pack"
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
	};
};

class CfgSlots
{
	class Slot_StalkerBeltContainer
	{
		name = "StalkerBeltContainer";
		displayName = "Container";
		ghostIcon = "set:dayz_inventory image:backpack";
	};
};

class CfgVehicles
{
	class SGE_Stalker_Sunrise_Belt;

	class BeltSGEContainer_Sunrise_Belt : SGE_Stalker_Sunrise_Belt
	{
		scope = 2;
		displayName = "Ceinture Sunrise (slot container)";
		// Ordre explicite = parent SGE (4 slots) + notre slot — évite perte des pouches et affichage équipé
		attachments[] =
		{
			"Stalker_Sunrise_Belt_Pouches_L",
			"Stalker_Sunrise_Belt_Pouches_R",
			"Belt_Cont",
			"Med_Pouch",
			"StalkerBeltContainer"
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
			class StalkerContainer
			{
				name = "StalkerBeltContainer";
				description = "";
				attachmentSlots[] = { "StalkerBeltContainer" };
				icon = "set:SGE_icons image:Belt_Cont";
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
		inventorySlot[] += { "StalkerBeltContainer" };
	};
	class BeltSGEContainer_AContainer2 : ON_AContainer2
	{
		scope = 2;
		displayName = "BeltSGEContainer2";
		inventorySlot[] += { "StalkerBeltContainer" };
	};
	class BeltSGEContainer_AContainer3 : ON_AContainer3
	{
		scope = 2;
		displayName = "BeltSGEContainer3";
		inventorySlot[] += { "StalkerBeltContainer" };
	};
	class BeltSGEContainer_AContainer4 : ON_AContainer4
	{
		scope = 2;
		displayName = "BeltSGEContainer4";
		inventorySlot[] += { "StalkerBeltContainer" };
	};
};
