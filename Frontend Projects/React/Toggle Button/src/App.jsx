import { useState } from 'react'
import './App.css'

function App() {
  const [vis, setVis] = useState(false);

  const handleToggle = () => {
    setVis(!vis);
  }

  return (
    <>
      <div className="container">
        <button onClick={handleToggle}>{vis ? "Hide Message" : "Show Message"}</button>
        {vis && <p id='msg'>This is a toggle button</p>}
      </div>
    </>
  )
}

export default App