<h1>设计模式之“单例模式”</h1>
<h2>定义：</h2>保证一个类只能有<u><b>一个实例</b></u>，并提供这个实例的全局访问点。<br>
<h2>要点：</h2>
1.不能有构造函数和Clone接口；<br>
2.不能直接使用双重检查锁，会出现<b>reorder</b>的问题，如要使用应加入标识；<br>
3.单例模式是为了提高对象性能所产生出的一种设计模式。<br>