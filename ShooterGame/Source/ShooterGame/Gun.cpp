// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

AGun::AGun()
{
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);
}

void AGun::BeginPlay()
{
	Super::BeginPlay();
}

void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGun::PullTrigger()
{
	UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, Mesh, TEXT("MuzzleFlashSocket"));

	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if (OwnerPawn == nullptr) { return; }
	AController* OwnerController = OwnerPawn->GetController();
	if (OwnerController == nullptr) { return; }

	FVector PawnLoc;
	FRotator PawnRot;
	OwnerController->GetPlayerViewPoint(OUT PawnLoc, OUT PawnRot);

	FVector End = PawnLoc + PawnRot.Vector() * MaxRange;

	FHitResult Hit;
	bool bSuccess = GetWorld()->LineTraceSingleByChannel(Hit, PawnLoc, End, ECollisionChannel::ECC_GameTraceChannel1);
	if (bSuccess)
	{
		FVector ShotDir = -PawnRot.Vector();
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactEffect,Hit.Location, ShotDir.Rotation());		
		AActor* ActorHit = Hit.GetActor();
		if (ActorHit != nullptr)
		{
			FPointDamageEvent DamageEvent(DamageAmount, Hit, ShotDir, nullptr);
			ActorHit->TakeDamage(DamageAmount, DamageEvent, OwnerController, this);
		}		
	}	
}

