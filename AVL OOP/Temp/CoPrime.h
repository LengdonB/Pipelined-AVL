#pragma once
#include "IPipe.h"
/// <summary>
/// The class CoPrime  has functions which checks if a value and key of a node are co-prime.(i.e. HCF=1)
/// </summary>
/// <seealso cref="IPipe" />
class CoPrime :
	public IPipe
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="CoPrime"/> class.
	/// </summary>
	CoPrime();
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

