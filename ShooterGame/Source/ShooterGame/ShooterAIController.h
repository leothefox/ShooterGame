// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShooterAIController.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERGAME_API AShooterAIController : public AAIController
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime) override;
	
protected:
	virtual void BeginPlay() override;

private:
	APawn* PlayerPawn;

	//UPROPERTY(EditAnywhere)
	//float AcceptanceRadius = 0.f;

	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AIBehavior;
};
