// Shoot Them Up Game


#include "Teleport.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"



ATeleport::ATeleport()
{
	OnActorBeginOverlap.AddDynamic(this, &ATeleport::EnterTeleportBox);
	OnActorEndOverlap.AddDynamic(this, & ATeleport::EndTeleportBox);
	bTeleporting = false;

}



void ATeleport::BeginPlay()
{
	Super::BeginPlay();
}

void ATeleport::EnterTeleportBox(AActor* OverlappedActor, AActor* OtherActor)
{
	//UE_LOG(LogTemp, Warning, TEXT("Warning"));
	if (OtherActor && OtherActor != this)
	{
		if (OtherTeleport)
		{
			ACharacter* Character = Cast<ACharacter>(OtherActor);
			if (Character && !OtherTeleport->bTeleporting)
			{
				bTeleporting = true;
				Character->SetActorRotation(OtherTeleport->GetActorRotation());
				Character->GetController()->SetControlRotation(Character->GetActorRotation());
				Character->SetActorLocation(OtherTeleport->GetActorLocation());

				UGameplayStatics::PlaySoundAtLocation(GetWorld(), EnterSound, GetActorLocation());
			}
		}
	}
}

void ATeleport::EndTeleportBox(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor && OtherActor != this)
	{
		if (OtherTeleport && !bTeleporting)
		{
			OtherTeleport->bTeleporting = false;
		}
	}
}
