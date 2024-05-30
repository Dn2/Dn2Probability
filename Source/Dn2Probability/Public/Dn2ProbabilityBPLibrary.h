// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Dn2ProbabilityBPLibrary.generated.h"

/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. 
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/

UENUM(BlueprintType)
enum EOutcomePins
{
	Failure,
	Success
};

UCLASS()
class DN2PROBABILITY_API UDn2ProbabilityBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()
public:
	//this is the basic Probability function that will take the item chance is 30% and then check if you'll get or not
	UFUNCTION(BlueprintCallable, /*BlueprintPure,*/ meta = (AutoCreateRefTerm = "RStream", DisplayName = "Simple % Probability Check", Keywords = "Simple Probability Check random chance rng"), Category = "Probability and RNG")
	static bool SimpleProbabilityCheck(int Probability, const FRandomStream& RStream, bool Seeded = false);

	UFUNCTION(BlueprintCallable, /*BlueprintPure,*/ meta = (AutoCreateRefTerm = "RStream", DisplayName = "Get Item By Probability", Keywords = "Cumulative Probability Check random chance rng"), Category = "Probability and RNG")
	static int GetItemByProbability(TArray<float> Probabilities, bool& Success, const FRandomStream& RStream, bool Seeded = false);

	UFUNCTION(BlueprintCallable, /*BlueprintPure,*/ meta = (AutoCreateRefTerm = "RStream", DisplayName = "Get Item By Probability Rarity", Keywords = "Cumulative Probability Check random chance rng"), Category = "Probability and RNG")
	static int GetItemByProbabilityRarity(TArray<float> Probabilities, bool& Success, const FRandomStream& RStream, bool Seeded = false);

	UFUNCTION(BlueprintCallable, /*BlueprintPure,*/ meta = (AutoCreateRefTerm = "RStream", DisplayName = "One In N Check", Keywords = "One In N Check random chance rng"), Category = "Probability and RNG")
	static bool OneInProbabilityCheck(const FRandomStream& RStream, int In = 1, bool Seeded = false);

	UFUNCTION(BlueprintCallable, /*BlueprintPure,*/ meta = (AutoCreateRefTerm = "RStream", DisplayName = "Chance In Probability Check", Keywords = "N In N Check random chance rng"), Category = "Probability and RNG")
	static bool ChanceInProbabilityCheck(const FRandomStream& RStream, int Probability = 1, int Chances = 2, bool Seeded = false);


	//Dice
	UFUNCTION(BlueprintCallable, /*BlueprintPure,*/ meta = (AutoCreateRefTerm = "RStream", DisplayName = "Get Dice Roll", Keywords = "Simple Probability Check random chance rng"), Category = "Probability and RNG")
	static int GetDieRoll(const FRandomStream& RStream, int Sides = 6, bool Seeded = false);
	 
	UFUNCTION(BlueprintCallable, /*BlueprintPure,*/ meta = (AutoCreateRefTerm = "RStream", DisplayName = "Get Multi Dice Roll", Keywords = "Simple Probability Check random chance rng"), Category = "Probability and RNG")
	static TArray<int> GetMultiDiceRoll(const FRandomStream& RStream, int Sides = 6, int DiceCount = 2, bool Seeded = false);

};
