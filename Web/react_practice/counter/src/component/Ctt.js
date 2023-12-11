import React, { useState } from "react";

function ctt() {
  const [ct, set] = useState(0);

  const inc = () => {
    set(ct + 1);
  };

  const dec = () => {
    set(ct - 1);
  };

  return (
    <div>
      <h1>Counter: {ct}</h1>
      <button onClick={inc}>Increment</button>
      <button onClick={dec}>Decrement</button>
    </div>
  );
}

export default ctt;