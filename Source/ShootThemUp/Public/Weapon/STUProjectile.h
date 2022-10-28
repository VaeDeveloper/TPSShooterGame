// Shoot Them Up Game

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sound/SoundCue.h"
#include "STUProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class USTUWeaponFXComponent;
class USoundCue;

UCLASS()
class SHOOTTHEMUP_API ASTUProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	ASTUProjectile();

	void SetShotDirection(const FVector& Direction) { ShotDirection = Direction; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Weapon")
	USphereComponent* CollisionComponent;

	UPROPERTY(VisibleAnywhere, Category = "Weapon")
	UProjectileMovementComponent* MovementComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
	USTUWeaponFXComponent* WeaponFXComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
	USoundCue* HitSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	float DamageRadius = 200.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	float DamageAmount = 70.0f;

	UPROPERTY(VisibleDefaultsOnly, Category = "Weapon")
	bool DoFullDamage = false;

	UPROPERTY(VisibleDefaultsOnly, Category = "Weapon")
	float LifeSeconds = 5.0f;

	virtual void BeginPlay() override;

private:
	FVector ShotDirection;

	UFUNCTION()
	void OnProjectileHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse,
	const FHitResult& Hit);

	AController* GetController() const;

};
