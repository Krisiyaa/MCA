import React, { useState } from 'react';

function Ct() {
  const [count, setCount] = useState(0);

  const increment = () => {
    setCount(count + 1);
  };

  const decrement = () => {
    setCount(count - 1);
  };

  return (
    <div className='a'>
      <h1>Counter: {count}</h1>
      <button onClick={increment}>Increment</button>
      <button onClick={decrement} disabled={count === 0}>
        Decrement
      </button>
    </div>
  );
}

export default Ct;