// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/FPSCharacterAnimInstance.h"
#include "Character/FPSCharacter.h"

UFPSCharacterAnimInstance::UFPSCharacterAnimInstance(const FObjectInitializer& ObjectInitializer):
	Super(ObjectInitializer), Owner(nullptr), GroundSpeed(0.0)
{
}

void UFPSCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	Owner = Cast<AFPSCharacter>(TryGetPawnOwner());
}

void UFPSCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if(Owner)
		GroundSpeed = Owner->GetGroundSpeed();
	UE_LOG(LogTemp, Warning, TEXT("SPEEEED : %f"), GroundSpeed);
}