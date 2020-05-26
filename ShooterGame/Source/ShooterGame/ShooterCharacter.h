// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

class AGun;

UCLASS()
class SHOOTERGAME_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AShooterCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

private:
	void MoveForBackwards(float AxisValue);
	void MoveSideways(float AxisValue);
	void MoveForBackwardsRate(float AxisValue);
	void MoveSidewaysRate(float AxisValue);
	void LookUpDownRate(float AxisValue);
	void LookSidewaysRate(float AxisValue);

	UPROPERTY(EditAnywhere)
	float RotationRate = 10.f;
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AGun> GunClass;
	UPROPERTY()
	AGun* Gun;
};
