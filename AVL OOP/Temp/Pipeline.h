#pragma once
#include"IPipe.h"

/// <summary>
/// class Pipeline contains function that is used to create different pipes
/// </summary>
/// <seealso cref="IPipe" />
class Pipeline :public
	IPipe
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="Pipeline"/> class.
	/// </summary>
	Pipeline();
	/// <summary>
	/// Sets the next function.
	/// </summary>
	/// <param name="nextFunction">The next function.</param>
	void setNextFunction(IPipe *nextFunction);
	/// <summary>
	/// Starts the specified value.
	/// </summary>
	/// <param name="value">The value.</param>
	/// <param name="current">The current.</param>
	/// <returns></returns>
	virtual int start(int value, Node *current);
};
