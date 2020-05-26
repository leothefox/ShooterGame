// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterCharacter.h"

AShooterCharacter::AShooterCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();
}


void AShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForBackwards"), this, &AShooterCharacter::MoveForBackwards);
	PlayerInputComponent->BindAxis(TEXT("MoveSideways"), this, &AShooterCharacter::MoveSideways);
	PlayerInputComponent->BindAxis(TEXT("LookUpDown"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("LookSideways"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent:: IE_Pressed, this, &ACharacter::Jump);

	// Controller axis rate
	PlayerInputComponent->BindAxis(TEXT("MoveForBackwardsRate"), this, &AShooterCharacter::MoveForBackwardsRate);
	PlayerInputComponent->BindAxis(TEXT("MoveSidewaysRate"), this, &AShooterCharacter::MoveSidewaysRate);
	PlayerInputComponent->BindAxis(TEXT("LookUpDownRate"), this, &AShooterCharacter::LookUpDownRate);
	PlayerInputComponent->BindAxis(TEXT("LookSidewaysRate"), this, &AShooterCharacter::LookSidewaysRate);
}

void AShooterCharacter::MoveForBackwards(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void AShooterCharacter::MoveSideways(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void AShooterCharacter::MoveForBackwardsRate(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}

void AShooterCharacter::MoveSidewaysRate(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}

void AShooterCharacter::LookUpDownRate(float AxisValue)
{
	AddControllerPitchInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}

void AShooterCharacter::LookSidewaysRate(float AxisValue)
{
	AddControllerYawInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}
