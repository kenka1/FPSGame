// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputMappingContext.h"
#include "InputActionValue.h"
#include "Engine/LocalPlayer.h"

#include "Character/FPSExtensionComponent.h"

UFPSExtensionComponent::UFPSExtensionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UFPSExtensionComponent::SetupPlayerInputComponent()
{
	const APawn* Owner = Cast<APawn>(GetOwner());
	check(Owner);
	UE_LOG(LogTemp, Warning, TEXT("Owner"));
	const APlayerController* Controller = Owner->GetController<APlayerController>();
	check(Controller);
	UE_LOG(LogTemp, Warning, TEXT("Controller"));
	const ULocalPlayer* LocalPlayer = Controller->GetLocalPlayer();
	check(LocalPlayer);
	UE_LOG(LogTemp, Warning, TEXT("LocalPlayer"));
	UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	check(Subsystem);
	UE_LOG(LogTemp, Warning, TEXT("Subsystem"));
	if (IMC)
		Subsystem->AddMappingContext(IMC, 0);

	UEnhancedInputComponent* InputComponent = Cast<UEnhancedInputComponent>(Owner->InputComponent);
	if (InputComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("Bind Action"));
		InputComponent->BindAction(IAMove, ETriggerEvent::Triggered, this, &ThisClass::Input_Move);
	}
}

void UFPSExtensionComponent::Input_Move(const FInputActionValue& InputActionValue)
{
	APawn* Owner = Cast<APawn>(GetOwner());
	check(Owner);

	const FVector2D Value = InputActionValue.Get<FVector2D>();
	if (Value.X != 0.0f)
	{
		UE_LOG(LogTemp, Warning, TEXT("PRESSED MOVE"));
		FVector MovementDirection = Owner->GetActorForwardVector();
		Owner->AddMovementInput(MovementDirection, Value.X);
	}

	if (Value.Y != 0.0f)
	{
		UE_LOG(LogTemp, Warning, TEXT("PRESSED MOVE"));
		FVector MovementDirection = Owner->GetActorRightVector();
		Owner->AddMovementInput(MovementDirection, Value.Y);
	}
}