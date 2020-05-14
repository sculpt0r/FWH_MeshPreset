// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "MyFactory.generated.h"

/**
 *
 */
UCLASS()
class FWH_MESHPRESET_API UMyFactory : public UFactory
{
	GENERATED_BODY()
		UMyFactory(const  FObjectInitializer& ObjectInitializer);
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;

};
