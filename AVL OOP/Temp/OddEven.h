#pragma once
#include "IPipe.h"
#include "INode.h"
/// <summary>
/// The class OddEven contains function that checks if a value is Even or Odd.
/// </summary>
/// <seealso cref="IPipe" />
class OddEven :
	public IPipe
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="OddEven"/> class.
	/// </summary>
	OddEven();
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

