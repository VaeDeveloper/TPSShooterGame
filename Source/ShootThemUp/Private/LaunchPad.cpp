// Shoot Them Up Game


#include "LaunchPad.h"
#include "STUBaseCharacter.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"



ALaunchPad::ALaunchPad()
{
    OverlapComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapComp"));
    OverlapComponent->SetBoxExtent(FVector(75, 75, 50));
    RootComponent = OverlapComponent;

    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
    MeshComponent->SetupAttachment(RootComponent);

    OverlapComponent->OnComponentBeginOverlap.AddDynamic(this, &ALaunchPad::OverlapLaunchPad);

    LaunchAngle = 35.0f;
    LaunchStrength = 1500.f;

}

void ALaunchPad::OverlapLaunchPad(UPrimitiveComponent* OverlappedComponent,
    AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    FRotator LaunchDirection = GetActorRotation();
    LaunchDirection.Pitch += LaunchAngle;
    FVector LaunchVelocity = LaunchDirection.Vector() * LaunchStrength;

    ACharacter* OtherCharacter = Cast<ACharacter>(OtherActor);
    if (OtherCharacter)
    {
        OtherCharacter->LaunchCharacter(LaunchVelocity, true, true);
        UGameplayStatics::PlaySound2D(GetWorld(), JumpSound);
       
    }
    else if (OtherComp && OtherComp->IsSimulatingPhysics())
    {
        OtherComp->AddImpulse(LaunchVelocity, NAME_None, true);

        //spawn fx
    }

}


