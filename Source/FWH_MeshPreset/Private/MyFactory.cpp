// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFactory.h"
#include "MyObject.h"

UMyFactory::UMyFactory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bCreateNew = true;
	SupportedClass = UMyObject::StaticClass();
}

UObject* UMyFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return NewObject<UMyObject>(InParent, Class, Name, Flags);
}
