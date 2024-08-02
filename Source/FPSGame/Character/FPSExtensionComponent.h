// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FPSExtensionComponent.generated.h"

class UInputAction;
class UInputMappingContext;
struct FInputActionValue;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FPSGAME_API UFPSExtensionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UFPSExtensionComponent();
	// may be this should give pointer from FPSCharacter ???
	void SetupPlayerInputComponent();
protected:
	
private:

	void Input_Move(const FInputActionValue& InputActionValue);
	void Input_Look(const FInputActionValue& InputActionValue);

	UPROPERTY(EditDefaultsOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UInputAction* IAMove;

	UPROPERTY(EditDefaultsOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UInputAction* IALook;

	UPROPERTY(EditDefaultsOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* IMC;
};
