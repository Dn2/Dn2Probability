// Copyright Epic Games, Inc. All Rights Reserved.

#include "Dn2ProbabilityBPLibrary.h"
#include "Dn2Probability.h"

UDn2ProbabilityBPLibrary::UDn2ProbabilityBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}


//this is the basic Probability function that will take the item chance is 30% and then check if you'll get or not
bool UDn2ProbabilityBPLibrary::SimpleProbabilityCheck(int Probability, const FRandomStream& RStream, bool Seeded)
{
	if (Seeded)
	{
		const int Rnd = RStream.RandRange(1, 100);
			UE_LOG(LogTemp, Warning, TEXT("Seed: %d"), RStream.GetInitialSeed());
		if(Rnd <= Probability)
		{

			return true;
		}
	}
	else
	{
		const int Rnd = FMath::RandRange(1, 100);

		if (Rnd <= Probability)
		{
			return true;
		}
	}

	return false;
}


int UDn2ProbabilityBPLibrary::GetItemByProbability(TArray<float> Probabilities, bool& Success, const FRandomStream& RStream, bool Seeded)
{
	//check for valid array
	if (!Probabilities.IsValidIndex(0))
	{
		Success = false;
		return -1;
	}

	TArray<float> CumulativeProbability;

	//check if array total sum is <= 100;
	int ProbabilitiesSum = 0;
	for (int n = 0; n < Probabilities.Num(); n++)
	{
		ProbabilitiesSum += Probabilities[n];
		CumulativeProbability.Add(ProbabilitiesSum);

		UE_LOG(LogTemp, Warning, TEXT("Prob: %f | Sum: %f"), Probabilities[n], ProbabilitiesSum);

		if (ProbabilitiesSum > 100.0f)
		{
			Success = false;
			return -2;
		}
	}

	int Rnd = 0;

	if (Seeded)
	{
		Rnd = RStream.RandRange(1, 100);
	}
	else
	{
		Rnd = FMath::RandRange(1, 100);
	}

	UE_LOG(LogTemp, Warning, TEXT("Rnd: %f"), Rnd);

	for (int i = 0; i < Probabilities.Num(); i++)
	{
		if (Rnd <= CumulativeProbability[i])
		{
			Success = true;
			return i;
		}
	}

	Success = false;
	return -3;
}


int UDn2ProbabilityBPLibrary::GetItemByProbabilityRarity(TArray<float> Probabilities, bool& Success, const FRandomStream& RStream, bool Seeded)
{
	//GetprobabilityByRarityModifer
	float ItemRaritySum = 0;

	for (int i = 0; i < Probabilities.Num(); i++)
	{
		ItemRaritySum += Probabilities[i];
	}

	const float ProbilityModifier = 100 / ItemRaritySum;


	//MakeCumulativeByProbabilityRarity
	float ProbabilitiesSum = 0;
	TArray<float> CumulativeByRarity;

	for (int i = 0; i < Probabilities.Num(); i++)
	{
		ProbabilitiesSum += Probabilities[i] * ProbilityModifier;
		CumulativeByRarity.Add(ProbabilitiesSum);
	}


	int Rnd = 0;

	if (Seeded)
	{
		Rnd = RStream.RandRange(1, 100);
	}
	else
	{
		Rnd = FMath::RandRange(1, 100);
	}


	for (int i = 0; i < Probabilities.Num(); i++)
	{
		if (Rnd <= CumulativeByRarity[i])
		{
			Success = true;
			return i;
		}
	}

	Success = false;
	return -1;
}


//This Function will return true if the item is lucky enough to be picked by a small chance of one in something
//and 100% chance to get the item if its 1 in 1
bool UDn2ProbabilityBPLibrary::OneInProbabilityCheck(const FRandomStream& RStream, int In, bool Seeded)
{
	if (Seeded)
	{
		const int Rnd = RStream.RandRange(1, In);

		if (Rnd <= 1)
		{
			return true;
		}
	}
	else
	{
		const int Rnd = FMath::RandRange(1, In);

		if (Rnd <= 1)
		{
			return true;
		}
	}

	return false;
}

//fix
//This Function will return true if the item is lucky enough to be picked by a small chance of num in something
//This can be used instead the first one without passing the second variable
bool UDn2ProbabilityBPLibrary::ChanceInProbabilityCheck(const FRandomStream& RStream, int Probability, int Chances, bool Seeded)
{

	if (Seeded)
	{
		const int Rnd = RStream.RandRange(1, Chances);

		if (Rnd <= Probability)
		{
			return true;
		}
	}
	else
	{
		const int Rnd = FMath::RandRange(1, Chances);

		if (Rnd <= Probability)
		{
			return true;
		}
	}

	return false;
}

int UDn2ProbabilityBPLibrary::GetDieRoll(const FRandomStream& RStream, int Sides /*= 6*/, bool Seeded)
{
	Sides = FMath::Clamp(Sides, 2, 100);

	if (Seeded)
	{
		return RStream.RandRange(1, Sides);
	}

	return FMath::RandRange(1, Sides);
}

TArray<int> UDn2ProbabilityBPLibrary::GetMultiDiceRoll(const FRandomStream& RStream, int Sides /*= 6*/, int DiceCount /*= 2*/, bool Seeded)
{
	Sides = FMath::Clamp(Sides, 2, 100);
	DiceCount = FMath::Clamp(DiceCount, 1, 100);
	TArray<int> Result;

	if (Seeded)
	{
		for (int i = 0; i < DiceCount; i++)
		{
			Result.Add(RStream.RandRange(1, Sides));
		}

		return Result;
	}
	//else

	for (int i = 0; i < DiceCount; i++)
	{
		Result.Add(FMath::RandRange(1, Sides));
	}

	return Result;
}

