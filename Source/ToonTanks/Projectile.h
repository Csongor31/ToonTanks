// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category="Combat")
	TObjectPtr<UStaticMeshComponent> ProjectileMesh;

	UPROPERTY(VisibleAnywhere, Category="Movement")
	TObjectPtr<class UProjectileMovementComponent> ProjectileMovementComponent;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& HitResult);

	UPROPERTY(EditAnywhere)
	float Damage = 50.f;

	UPROPERTY(EditAnywhere, Category="Combat")
	TObjectPtr<UParticleSystem> HitParticle;

	UPROPERTY(VisibleAnywhere, Category="Combat")
	TObjectPtr<UParticleSystemComponent> TrailParticles;

	UPROPERTY(EditAnywhere, Category="Combat")
	TObjectPtr<USoundBase> LaunchSound;

	UPROPERTY(EditAnywhere, Category="Combat")
	TObjectPtr<USoundBase> HitSound;

	UPROPERTY(EditAnywhere, Category="Combat")
	TSubclassOf<class UCameraShakeBase> HitCameraShakeClass;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
