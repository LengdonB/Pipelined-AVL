#pragma once
#include "IPipe.h"
/// <summary>
/// Finds if two consecutive traversed nodes are both even or both odd.
/// </summary>
/// <seealso cref="IPipe" />
class EvenOddPair :
	public IPipe
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="EvenOddPair"/> class.
	/// </summary>
	EvenOddPair();
	/// <summary>
	/// Sets the next function.
	/// </summary>
	/// <param name="nextFunction">The next function.</param>
	virtual void setNextFunction(IPipe *nextFunction);
	/// <summary>
	/// Starts for the specified value and node.
	/// </summary>
	/// <param name="value">The value.</param>
	/// <param name="current">The current.</param>
	/// <returns></returns>
	int start(int value, Node* current);
};

