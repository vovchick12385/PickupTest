#include "EquippedCardComponent.h"
#include <Kismet/KismetSystemLibrary.h>


UEquippedCardComponent::UEquippedCardComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

ACard* UEquippedCardComponent::GetCurrentCard(int num)
{
	if (EquippedCards.Num() >= num)
	{
		return EquippedCards[num];
	}
	return false;
}

void UEquippedCardComponent::EquipCard(ACard* Card)
{
	EquippedCards.AddUnique(Card);
	UKismetSystemLibrary::PrintString(this, TEXT("Pickup Card"));
}


