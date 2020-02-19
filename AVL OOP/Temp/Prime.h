#pragma once
#include "IPipe.h"
#include "INode.h"
/// <summary>
/// class Prime contains function to check if value is prime or not
/// </summary>
/// <seealso cref="IPipe" />
class Prime :
	public IPipe
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="Prime"/> class.
	/// </summary>
	Prime();
	/// <summary>
	/// Sets the next function.
	/// </summary>
	/// <param name="nextFunction">The next function.</param>
	virtual void setNextFunction(IPipe *nextFunction);
	/// <summary>
	/// Starts the specified value.
	/// </summary>
	/// <param name="value">The value.</param>
	/// <param name="current">The current.</param>
	/// <returns></returns>
	int start(int value, Node* current);
};

