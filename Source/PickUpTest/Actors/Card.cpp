#include "Card.h"
#include "../PickUpTestCharacter.h"
#include "../ActorComponent/EquippedCardComponent.h"
#include "../Types.h"


ACard::ACard()
{
	CardMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CardMesh"));
	CardMesh->SetupAttachment(RootComponent);

	CardTexture = CreateDefaultSubobject<UTexture>(TEXT("CardTexture"));
}

void ACard::Interact(APickUpTestCharacter* Character)
{
	Character->Equipment->EquipCard(this);
}

FName ACard::GetActionEventName() const
{
	return ActionInteract;
}

ECardType ACard::GetCard() const
{
	return CardType;
}
