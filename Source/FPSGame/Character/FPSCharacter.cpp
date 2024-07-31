// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/FPSCharacter.h"
#include "Camera/FPSCameraComponent.h"

#include "Character/FPSExtensionComponent.h"

AFPSCharacter::AFPSCharacter(const FObjectInitializer& ObjectInitializer):
	Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;

	CameraComponent = CreateDefaultSubobject<UFPSCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(GetRootComponent());
	
}

void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UFPSExtensionComponent* FPSComponent = FindComponentByClass<UFPSExtensionComponent>();
	if (FPSComponent)
		FPSComponent->SetupPlayerInputComponent();
}

