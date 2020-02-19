#pragma once
#include"INode.h"
/// <summary>
/// Thc class IPipe is an abstract class which is inherited by other classes that can be added to pipe
/// </summary>
class IPipe
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="IPipe"/> class.
	/// </summary>
	IPipe();
	/// <summary>
	/// The nextfunction keeps track of next function.
	/// </summary>
	IPipe *nextFunction;
	/// <summary>
	/// Sets the next function.
	/// </summary>
	/// <param name="nextFunction">The next function.</param>
	virtual void setNextFunction(IPipe *nextFunction) = 0;
	/// <summary>
	/// Starts the specified value.
	/// </summary>
	/// <param name="value">The value.</param>
	/// <param name="current">The current.</param>
	/// <returns></returns>
	virtual int start(int value, Node *current) = 0;
};