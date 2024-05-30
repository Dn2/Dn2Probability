# Dn2Probability
 Unreal Engine Probability plugin based on [FadrikAlexander's](https://fadrikalexander.itch.io/) Unity [probability system/tutorial](https://www.youtube.com/watch?v=84rs2Q0z9ak). Use for drop rates, rpg weapon accuracy, loot etc.  

Made this blueprint library  for my own convenience and sharing here and on github maybe. Its mostly untested but I'll try and update when issues are found.  

**Compatibility:** Made in 5.1 but works in 4.7 without any modifications. It SHOULD work/compile for other engine versions, it try it. If it doesn't load try compiling it for that version first by adding it to your project.  

**SimpleProbabilityCheck()**: Given N, out of 100, return true if successful  
**GetItemByProbability()**: Return a result from a list of items with different probabilities  
**GetItemByProbabilityRarity()**: Same as above but by rarity  
**OneInProbabilityCheck()**: Return the result of a 1 on N probability check  
**ChanceInProbabilityCheck()**: Return the result of a N in N probability check  
**GetDieRoll()**: Get the result of rolling an N sided die  
**GetMultiDiceRoll()**: Get the result of multiple N sided dice

  

## Install Plugin

Copy the "Discord" folder to:

*   your project's plugin folder (YourProject\\Plugins)

  

## Blueprint Usage

Search for "Probability" and it should list the nodes for you to use.  
  

## C++ Usage

Add "Dn2Probability" to "PublicDependencyModuleNames" in YourGame.Build.cs  

```PublicDependencyModuleNames.AddRange(new string\[\] { "Dn2Probability", "Core", "CoreUObject", "Engine", "InputCore" });```

Add the include  

```#include "Dn2ProbabilityBPLibrary.h"```

Call the probability function like so

```UDn2ProbabilityBPLibrary::OneInProbabilityCheck(2)```