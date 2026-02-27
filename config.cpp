/*
	BeltSGEContainer - Mod de compatibilité DayZ
	Ajoute un slot sur la ceinture SGE Stalker Sunrise pour y attacher ON_AContainer1.

	Dépend de: STALKER Equipment (addon SGE_ClearSky) + STALKER Containers Pack
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
		displayName = "$STR_BeltSGEContainer_Slot";
		ghostIcon = "set:dayz_inventory image:backpack";
	};
};

class CfgVehicles
{
	class SGE_Stalker_Sunrise_Belt;

	class BeltSGEContainer_Sunrise_Belt : SGE_Stalker_Sunrise_Belt
	{
		scope = 2;
		displayName = "$STR_BeltSGEContainer_Belt";
		attachments[] += { "StalkerBeltContainer" };
		class GUIInventoryAttachmentsProps
		{
			class StalkerContainer
			{
				name = "$STR_BeltSGEContainer_Slot";
				description = "";
				attachmentSlots[] = { "StalkerBeltContainer" };
				icon = "set:dayz_inventory image:backpack";
			};
		};
	};

	class ON_AContainer1;

	class BeltSGEContainer_AContainer1 : ON_AContainer1
	{
		scope = 2;
		displayName = "$STR_BeltSGEContainer_Container";
		inventorySlot[] += { "StalkerBeltContainer" };
	};
};
