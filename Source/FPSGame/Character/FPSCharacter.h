// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FPSCharacter.generated.h"

class UFPSCameraComponent;
class USpringArmComponent;

UCLASS()
class FPSGAME_API AFPSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AFPSCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	inline double GetGroundSpeed() const { return GroundSpeed; }

protected:
	virtual void BeginPlay() override;

private:
	void CalculateGroundSpeed();
	double GroundSpeed;

	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	UFPSCameraComponent* CameraComponent;

};
