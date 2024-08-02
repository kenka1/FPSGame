// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/FPSCharacter.h"
#include "Camera/FPSCameraComponent.h"

#include "Character/FPSExtensionComponent.h"
#include "GameFramework/SpringArmComponent.h"

AFPSCharacter::AFPSCharacter(const FObjectInitializer& ObjectInitializer):
	Super(ObjectInitializer), GroundSpeed(0.0)
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->SetupAttachment(GetRootComponent());

	CameraComponent = CreateDefaultSubobject<UFPSCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = true;
	
}

void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFPSCharacter::CalculateGroundSpeed()
{
	FVector vel = GetVelocity();
	GroundSpeed = FMath::Sqrt(vel.X * vel.X + vel.Y * vel.Y);

}

void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CalculateGroundSpeed();

}

void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UFPSExtensionComponent* FPSComponent = FindComponentByClass<UFPSExtensionComponent>();
	if (FPSComponent)
		FPSComponent->SetupPlayerInputComponent();
}

