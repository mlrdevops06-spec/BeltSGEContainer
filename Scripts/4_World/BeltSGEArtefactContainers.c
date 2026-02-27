// Containers ceinture SGE : SGE_Stalker_Belt_Cont1/2/3 utilisent les slots Artifacts1/2/3 (ON_Container_Pack), 1 à 3 artefacts Redux max.

modded class Container_Base
{
	int CountArtefactsInContainer()
	{
		int limit = GetArtefactLimit();
		if (limit <= 0 || !GetInventory())
			return 0;
		int id1 = InventorySlots.GetSlotIdFromString("Artifacts1");
		int id2 = InventorySlots.GetSlotIdFromString("Artifacts2");
		int id3 = InventorySlots.GetSlotIdFromString("Artifacts3");
		int count = 0;
		int slotCount = GetInventory().GetAttachmentSlotsCount();
		for (int i = 0; i < slotCount; i++)
		{
			int slotId = GetInventory().GetAttachmentSlotId(i);
			if (slotId == id1 || (limit >= 2 && slotId == id2) || (limit >= 3 && slotId == id3))
			{
				EntityAI att = GetInventory().GetAttachmentFromIndex(i);
				if (att && att.IsKindOf("MH_ART_Redux_Base"))
					count++;
			}
		}
		return count;
	}

	int GetArtefactLimit()
	{
		string c = this.ClassName();
		if (c == "SGE_Stalker_Belt_Cont1") return 1;
		if (c == "SGE_Stalker_Belt_Cont2") return 2;
		if (c == "SGE_Stalker_Belt_Cont3") return 3;
		return -1;
	}

	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		int limit = GetArtefactLimit();
		if (limit > 0)
		{
			if (!attachment || !attachment.IsKindOf("MH_ART_Redux_Base"))
				return false;
			if (CountArtefactsInContainer() >= limit)
				return false;
			return true;
		}
		return super.CanReceiveAttachment(attachment, slotId);
	}

	override bool CanLoadAttachment(EntityAI attachment)
	{
		int limit = GetArtefactLimit();
		if (limit > 0)
		{
			if (!attachment || !attachment.IsKindOf("MH_ART_Redux_Base"))
				return false;
			if (CountArtefactsInContainer() >= limit)
				return false;
			return true;
		}
		return super.CanLoadAttachment(attachment);
	}
}
