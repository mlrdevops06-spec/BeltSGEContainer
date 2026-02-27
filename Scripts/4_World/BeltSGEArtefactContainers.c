// Containers ceinture SGE : SGE_Stalker_Belt_Cont1/2/3 n'acceptent que des artefacts Redux (1, 2 ou 3 max).

modded class Container_Base
{
	int CountArtefactsInContainer()
	{
		int count = 0;
		if (!GetInventory() || !GetInventory().GetCargo())
			return 0;
		CargoBase cargo = GetInventory().GetCargo();
		for (int i = 0; i < cargo.GetItemCount(); i++)
		{
			EntityAI item = cargo.GetItem(i);
			if (item && item.IsKindOf("MH_ART_Redux_Base"))
				count++;
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
