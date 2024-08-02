// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "FPSCharacterAnimInstance.generated.h"


class AFPSCharacter;

UCLASS()
class FPSGAME_API UFPSCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UFPSCharacterAnimInstance(const FObjectInitializer& ObjectInitializer);
	void NativeInitializeAnimation() override;
	void NativeUpdateAnimation(float DeltaSeconds) override;
private:
	AFPSCharacter* Owner;
	double GroundSpeed;
};
