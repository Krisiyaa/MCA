import React, { useState } from 'react';

function Rep() {

  const handleClick = () => {
    const txt = document.getElementById('one');
    const ip = document.getElementById('ip').value;
    txt.innerText=ip;
  };

  return (
    <div className='a'>
      <h1 id="one">Krishant Chauhan</h1>
      <input id="ip" />
      <button onClick={handleClick}>Change Text</button>
    </div>
  );
}

export default Rep;