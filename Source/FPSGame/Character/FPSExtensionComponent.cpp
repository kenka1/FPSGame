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

	const APlayerController* Controller = Owner->GetController<APlayerController>();
	check(Controller);
	
	const ULocalPlayer* LocalPlayer = Controller->GetLocalPlayer();
	check(LocalPlayer);
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	check(Subsystem);
	
	if (IMC)
		Subsystem->AddMappingContext(IMC, 0);

	UEnhancedInputComponent* InputComponent = Cast<UEnhancedInputComponent>(Owner->InputComponent);
	if (InputComponent)
	{
		InputComponent->BindAction(IAMove, ETriggerEvent::Triggered, this, &ThisClass::Input_Move);
		InputComponent->BindAction(IALook, ETriggerEvent::Triggered, this, &ThisClass::Input_Look);
	}
}

void UFPSExtensionComponent::Input_Move(const FInputActionValue& InputActionValue)
{
	APawn* Owner = Cast<APawn>(GetOwner());

	const FVector2D Value = InputActionValue.Get<FVector2D>();
	if (Value.X != 0.0f)
	{
		FVector MovementDirection = Owner->GetActorForwardVector();
		Owner->AddMovementInput(MovementDirection, Value.X);
	}

	if (Value.Y != 0.0f)
	{
		FVector MovementDirection = Owner->GetActorRightVector();
		Owner->AddMovementInput(MovementDirection, Value.Y);
	}
}

void UFPSExtensionComponent::Input_Look(const FInputActionValue& InputActionValue)
{
	APawn* Owner = Cast<APawn>(GetOwner());

	const FVector2D Value = InputActionValue.Get<FVector2D>();
	if (Value.X != 0)
	{
		Owner->AddControllerYawInput(Value.X);
	}
	if (Value.Y != 0)
	{
		Owner->AddControllerPitchInput(-Value.Y);
	}

}